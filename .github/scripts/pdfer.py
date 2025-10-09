#!/usr/bin/env python3

"""
Script de geração do Almanaque BRUTE.

Responsabilidades principais:
- Montar `LaTeX/generated/codigos.tex` a partir da árvore de `Codigos/`;
- Descobrir automaticamente os capítulos definidos em `LaTeX/chapters/**/index.tex`;
- Reescrever `LaTeX/main.tex` com os capítulos encontrados;
- Compilar o PDF com `rubber` e copiar os artefatos para `PDF/`;
- Atualizar o `README.md` raiz com a tabela de conteúdos de `Codigos/`.
"""

from __future__ import annotations

import re
import shutil
import subprocess
from pathlib import Path
from typing import Iterable, List

ROOT = Path(__file__).resolve().parents[2]
CODIGOS_DIR = ROOT / "Codigos"
LATEX_DIR = ROOT / "LaTeX"
CHAPTERS_DIR = LATEX_DIR / "chapters"
GENERATED_DIR = LATEX_DIR / "generated"
MAIN_TEX = LATEX_DIR / "main.tex"
README_TEMPLATE = ROOT / "docs/readme_intro.md"
README_OUTPUT = ROOT / "README.md"
PDF_DIR = ROOT / "PDF"
OUTPUT_PDF = PDF_DIR / "Almanaque.pdf"
OUTPUT_TEX = PDF_DIR / "Almanaque.tex"

GITIGNORE_PATTERNS: List[re.Pattern[str]] = []


def gitignore_to_regex(pattern: str) -> re.Pattern[str] | None:
    pattern = pattern.strip()
    if not pattern or pattern.startswith("#"):
        return None
    if pattern.startswith("/"):
        pattern = pattern[1:]
    pattern = pattern.replace(".", r"\.").replace("*", ".*").replace("?", ".")
    return re.compile(pattern)


def load_gitignore() -> List[re.Pattern[str]]:
    gitignore_path = ROOT / ".gitignore"
    patterns: List[re.Pattern[str]] = []
    if gitignore_path.exists():
        for line in gitignore_path.read_text(encoding="utf-8").splitlines():
            regex = gitignore_to_regex(line)
            if regex:
                patterns.append(regex)
    return patterns


def relative_to_root(path: Path) -> Path:
    try:
        return path.relative_to(ROOT)
    except ValueError:
        return path


def is_gitignored(path: Path) -> bool:
    rel = relative_to_root(path).as_posix()
    return any(pattern.match(rel) for pattern in GITIGNORE_PATTERNS)


def is_tracked_by_git(path: Path) -> bool:
    rel = relative_to_root(path).as_posix()
    if not rel:
        rel = "."
    try:
        result = subprocess.run(
            ["git", "ls-files", "--error-unmatch", rel],
            cwd=ROOT,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        return result.returncode == 0
    except Exception:
        return False


def latex_escape(text: str) -> str:
    replacements = {
        "_": r"\_",
        "%": r"\%",
        "&": r"\&",
        "#": r"\#",
        "$": r"\$",
        "{": r"\{",
        "}": r"\}",
        "~": r"\textasciitilde{}",
        "^": r"\textasciicircum{}",
    }
    escaped = []
    for char in text:
        escaped.append(replacements.get(char, char))
    return "".join(escaped)


def printa_arquivo(path: Path, dest: Path) -> None:
    dest.write_text(path.read_text(encoding="utf-8"), encoding="utf-8")


def write_section_header(path: Path, file_handle, level: int) -> None:
    name = latex_escape(path.name.replace("-", " "))
    if level == 0:
        file_handle.write(f"\\section{{{name}}}\n\n")
    elif level == 1:
        file_handle.write(f"\\subsection{{{name}}}\n\n")
    elif level == 2:
        file_handle.write(f"\\subsubsection{{{name}}}\n\n")
    else:
        file_handle.write(f"\\paragraph{{{name}}}\n\n")


def printa_readme(path: Path, file_handle) -> None:
    def print_linha(line: str, dest) -> None:
        in_math = False
        in_inline_code = False
        in_bold = False
        i = 0
        while i < len(line):
            if line[i] == "`":
                dest.write("}" if in_inline_code else "\\texttt{")
                in_inline_code = not in_inline_code
            elif line[i] == "$" and i + 1 < len(line) and line[i + 1] == "$":
                in_math = not in_math
                dest.write(line[i : i + 2])
                i += 1
            elif line[i] == "$":
                in_math = not in_math
                dest.write(line[i])
            elif line[i] == "*" and i + 1 < len(line) and line[i + 1] == "*":
                dest.write("}" if in_bold else "\\textbf{")
                in_bold = not in_bold
                i += 1
            elif line[i] == "#":
                it = i
                now = ""
                while it < len(line) and line[it] != "[":
                    it += 1
                if it + 1 < len(line) and line[it] == "[":
                    now = line[it + 1 : line.find("]")]
                    it = line.find("]")
                if it + 1 < len(line) and line[it + 1] == "(":
                    while it < len(line) and line[it] != ")":
                        it += 1
                dest.write("\\textbf{" + now + "} ")
                i = it
            else:
                char = line[i]
                if char in ["%", "~", "_"] and not in_math and not in_inline_code:
                    dest.write("\\")
                if char == "&" and in_inline_code:
                    dest.write("\\")
                if char in ["_", "^"] and in_inline_code:
                    dest.write("\\")
                dest.write(char)
            i += 1
        dest.write("\n")

    lines = path.read_text(encoding="utf-8").splitlines()
    while lines and (lines[0].startswith("#") or lines[0].strip() == ""):
        lines.pop(0)
    while lines and lines[-1].strip() == "":
        lines.pop()

    file_handle.write("\\begingroup\\footnotesize\n")

    in_code = False
    in_list = False
    for line in lines:
        if "<!-- DESCRIPTION -->" in line:
            continue
        if line.startswith("```"):
            if in_list:
                file_handle.write("\\end{itemize}\n\n")
                in_list = False
            if in_code:
                file_handle.write("\\end{lstlisting}\n\n")
            else:
                file_handle.write("\\begin{lstlisting}[language=C++]\n")
            in_code = not in_code
        elif in_code:
            file_handle.write(line + "\n")
        elif line.startswith("-") or line.startswith("+"):
            if not in_list:
                file_handle.write("\\begin{itemize}\n")
                in_list = True
            item = line[1:].strip()
            file_handle.write("\\item ")
            print_linha(item, file_handle)
        else:
            if in_list:
                file_handle.write("\\end{itemize}\n\n")
                in_list = False
            print_linha(line, file_handle)

    if in_list:
        file_handle.write("\\end{itemize}\n\n")
    file_handle.write("\\par\\endgroup\n\\medskip\n\n")


def printa_codigo(path: Path, file_handle) -> None:
    clean_name = latex_escape(path.name)
    file_handle.write("\\begingroup\\footnotesize\n")
    file_handle.write(f"\\textbf{{Arquivo:}} {clean_name}\\par\n")
    file_handle.write("\\begin{lstlisting}[language=C++]\n")
    file_handle.write(path.read_text(encoding="utf-8"))
    file_handle.write("\\end{lstlisting}\n")
    file_handle.write("\\endgroup\n\\medskip\n\n")


def dfs_codigos(path: Path, file_handle, level: int = 0) -> None:
    if not is_tracked_by_git(path):
        return

    write_section_header(path, file_handle, level)

    entries = sorted(path.iterdir(), key=lambda p: p.name)
    endpoint = False
    for child in entries:
        if child.is_dir():
            dfs_codigos(child, file_handle, level + 1)
        else:
            endpoint = True

    if endpoint:
        readme = path / "README.md"
        if not readme.exists():
            raise FileNotFoundError(f"README.md não encontrado em {path}")
        printa_readme(readme, file_handle)

        code_files = [
            f
            for f in path.iterdir()
            if f.is_file()
            and not f.name.lower().endswith(".md")
            and not is_gitignored(f)
        ]
        for code in sorted(code_files, key=lambda p: p.name):
            printa_codigo(code, file_handle)


def generate_codigos_tex(destination: Path) -> None:
    GENERATED_DIR.mkdir(parents=True, exist_ok=True)
    with destination.open("w", encoding="utf-8") as handle:
        handle.write("% Conteúdo gerado automaticamente a partir de Codigos/\n\n")
        extra_dir = CODIGOS_DIR / "Extra"
        if extra_dir.exists():
            dfs_codigos(extra_dir, handle, 0)
        for child in sorted(CODIGOS_DIR.iterdir(), key=lambda p: p.name):
            if child.is_dir() and child.name != "Extra":
                dfs_codigos(child, handle, 0)


def collect_chapter_inputs() -> List[str]:
    if not CHAPTERS_DIR.exists():
        return []
    indices = sorted(
        CHAPTERS_DIR.glob("**/index.tex"),
        key=lambda p: p.relative_to(CHAPTERS_DIR).as_posix(),
    )
    result = []
    for index in indices:
        relative = index.relative_to(LATEX_DIR).with_suffix("")
        result.append(relative.as_posix())
    return result


def write_main_tex(chapter_inputs: Iterable[str], extra_inputs: Iterable[str]) -> None:
    lines: List[str] = [
        r"\input{preamble}",
        "",
        r"\begin{document}",
        r"\date{\today}",
        r"\maketitle",
        r"\begin{multicols}{3}",
        r"\tableofcontents",
        r"\end{multicols}",
        r"\clearpage",
        r"\begin{multicols}{3}",
        "",
    ]
    chapter_inputs = list(chapter_inputs)
    extra_inputs = list(extra_inputs)
    if chapter_inputs:
        lines.append("% Capítulos principais")
        for entry in chapter_inputs:
            lines.append(f"\\input{{{entry}}}")
        lines.append("")
    if extra_inputs:
        lines.append("% Conteúdo gerado automaticamente")
        for entry in extra_inputs:
            lines.append(f"\\input{{{entry}}}")
        lines.append("")
    lines.append(r"\end{multicols}")
    lines.append(r"\end{document}")
    MAIN_TEX.write_text("\n".join(lines) + "\n", encoding="utf-8")


def compile_pdf() -> None:
    target = MAIN_TEX.name
    if shutil.which("rubber"):
        result = subprocess.run(["rubber", "--pdf", "--inplace", target], cwd=LATEX_DIR)
        if result.returncode != 0:
            raise RuntimeError("Erro ao compilar o arquivo LaTeX/main.tex com rubber.")
    elif shutil.which("latexmk"):
        result = subprocess.run(
            ["latexmk", "-pdf", "-halt-on-error", "-interaction=nonstopmode", target],
            cwd=LATEX_DIR,
        )
        if result.returncode != 0:
            raise RuntimeError("Erro ao compilar o arquivo LaTeX/main.tex com latexmk.")
    elif shutil.which("pdflatex"):
        for _ in range(2):
            result = subprocess.run(
                ["pdflatex", "-interaction=nonstopmode", "-halt-on-error", target],
                cwd=LATEX_DIR,
            )
            if result.returncode != 0:
                raise RuntimeError("Erro ao compilar o arquivo LaTeX/main.tex com pdflatex.")
    else:
        raise RuntimeError(
            "Nenhum compilador LaTeX suportado encontrado (rubber, latexmk ou pdflatex)."
        )


def finalize_outputs() -> None:
    pdf_path = LATEX_DIR / "main.pdf"
    if not pdf_path.exists():
        raise FileNotFoundError("PDF não foi gerado, ocorreu algum erro.")
    PDF_DIR.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(pdf_path, OUTPUT_PDF)
    shutil.copyfile(MAIN_TEX, OUTPUT_TEX)


def cleanup_aux_files() -> None:
    extensions = [
        ".aux",
        ".log",
        ".out",
        ".toc",
        ".synctex.gz",
        ".rubbercache",
        ".fdb_latexmk",
        ".fls",
    ]
    for ext in extensions:
        candidate = MAIN_TEX.with_suffix(ext)
        if candidate.exists():
            candidate.unlink()
    pdf_path = LATEX_DIR / "main.pdf"
    if pdf_path.exists():
        pdf_path.unlink()


def dfs_readmes(path: Path, file_handle, level: int, base: str) -> None:
    if not is_tracked_by_git(path):
        return
    name = path.name.replace("-", " ")
    if level == 0:
        file_handle.write(f"### [{name}]({base})\n\n")
    else:
        indent = "  " * (level - 1)
        file_handle.write(f"{indent}- [{name}]({base})\n")
    for child in sorted(path.iterdir(), key=lambda p: p.name):
        if child.is_dir():
            dfs_readmes(child, file_handle, level + 1, f"{base}/{child.name}")


def update_readme() -> None:
    if not README_TEMPLATE.exists():
        raise FileNotFoundError("Template do README não encontrado em docs/readme_intro.md.")
    content = README_TEMPLATE.read_text(encoding="utf-8")
    with README_OUTPUT.open("w", encoding="utf-8") as handle:
        handle.write(content.rstrip() + "\n\n")
        handle.write("## Tabela de Conteúdos\n\n")
        for child in sorted(CODIGOS_DIR.iterdir(), key=lambda p: p.name):
            if child.is_dir():
                dfs_readmes(child, handle, 0, f"Codigos/{child.name}")
        handle.write("\n")


def main() -> None:
    if not CODIGOS_DIR.exists():
        raise FileNotFoundError("Esse script deve ser executado na raiz do repositório.")

    global GITIGNORE_PATTERNS
    GITIGNORE_PATTERNS = load_gitignore()

    generate_codigos_tex(GENERATED_DIR / "codigos.tex")

    chapter_inputs = collect_chapter_inputs()
    extra_inputs: List[str] = []
    codigos_relative = (GENERATED_DIR / "codigos.tex").relative_to(LATEX_DIR).with_suffix("")
    if (GENERATED_DIR / "codigos.tex").exists():
        extra_inputs.append(codigos_relative.as_posix())

    write_main_tex(chapter_inputs, extra_inputs)
    compile_pdf()
    finalize_outputs()
    cleanup_aux_files()
    update_readme()


if __name__ == "__main__":
    main()

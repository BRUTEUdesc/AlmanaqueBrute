#!/usr/bin/env python3

import os
import re
from pathlib import Path

def gitignore_to_regex(pattern):
    pattern = pattern.strip()
    if not pattern or pattern.startswith('#'):
        return None
    if pattern.startswith('/'):
        pattern = pattern[1:]
    pattern = pattern.replace('.', r'\.').replace('*', '.*').replace('?', '.')
    return re.compile(pattern)


def is_gitignored(file_path):
    global gitignore
    for pattern in gitignore:
        if pattern and pattern.match(str(file_path)):
            return True
    return False


def printa_arquivo(path: Path, FILE: Path):
    with open(path, "r") as f:
        FILE.write(f.read())


def printa_section(path: Path, FILE: Path, level: int):
    name = path.name.replace("-", " ")
    name = name.strip()
    if level == 0:
        FILE.write("\\newpage\n\n")
        FILE.write("%%%%%%\n")
        for i in range(2):
            FILE.write("%\n")
        FILE.write(f"% {name}\n")
        for i in range(2):
            FILE.write("%\n")
        FILE.write("%%%%%%\n\n")
        FILE.write(f"\\chapter{{{name}}}\n\n")
    elif level == 1:
        FILE.write(f"\\section{{{name}}}\n")
    elif level == 2:
        FILE.write(f"\\subsection{{{name}}}\n")
    elif level == 3:
        FILE.write(f"\\subsubsection{{{name}}}\n")


def printa_readme(path: Path, FILE: Path):
    def print_linha(line, dest):
        in_math = False
        in_inline_code = False
        in_bold = False
        i = 0
        while i < len(line):
            if line[i] == '`':
                if in_inline_code:
                    dest.write("}")
                else:
                    dest.write("\\texttt{")
                in_inline_code = not in_inline_code
            elif line[i] == '$' and i + 1 < len(line) and line[i + 1] == '$':
                in_math = not in_math
                dest.write(line[i])
                dest.write(line[i + 1])
                i += 1
            elif line[i] == '$':
                in_math = not in_math
                dest.write(line[i])
            elif line[i] == '*' and i + 1 < len(line) and line[i + 1] == '*':
                if in_bold:
                    dest.write("}")
                else:
                    dest.write("\\textbf{")
                in_bold = not in_bold
                i += 1
            elif line[i] == '#':
                it = i
                now = ""
                while it < len(line) and line[it] != '[':
                    it += 1
                if it + 1 < len(line) and line[it] == '[':
                    now = line[it + 1:line.find(']')]   
                    it = line.find(']')
                if it + 1 < len(line) and line[it + 1] == '(':
                    while it < len(line) and line[it] != ')':
                        it += 1
                dest.write("\\textbf{" + now + "} ")
                i = it
            else:
                if line[i] in ['%', '&', '~', '_'] and not in_math and not in_inline_code:
                    dest.write('\\')
                if line[i] in ['_', '^'] and in_inline_code:
                    dest.write("\\")
                dest.write(line[i])
            i += 1
        dest.write("\n")

    with open(path, "r") as f:
        in_code = False
        in_list = False
        lines = f.readlines()

        while lines[0].startswith("#") or lines == "\n":
            lines.pop(0)

        for line in lines:
            if "<!-- DESCRIPTION -->" in line:
                FILE.write("")
            elif line.startswith("```"):
                if in_list:
                    FILE.write("\\end{itemize}\n\n")
                    in_list = False
                if in_code:
                    FILE.write("\\end{lstlisting}\n\n")
                else:  
                    FILE.write("\\begin{lstlisting}[language=C++]\n")
                in_code = not in_code

            elif in_code: 
                FILE.write(line)

            elif line.startswith("-") or line.startswith("+"):
                if not in_list:
                    FILE.write("\\begin{itemize}\n")
                    in_list = True
                item = line[1:].strip()
                FILE.write("\\item ")
                print_linha(item, FILE)

            else:
                if in_list:
                    FILE.write("\\end{itemize}\n\n")
                    in_list = False
                print_linha(line, FILE)

        if in_list:
            FILE.write("\\end{itemize}\n\n")
            in_list = False

        FILE.write("\\hfill\n\n")


def printa_codigo(path: Path, FILE: Path):
    clean_name = path.name.replace("_", "\\_")
    FILE.write("Codigo: " + clean_name + "\n\n")
    max_lenght = 100000
    two_columns = False

    with open(path, "r") as f:
        for line in f.readlines():
            if len(line) > max_lenght:
                two_columns = False

    if two_columns:
        FILE.write("\\begin{multicols}{2}\n")

    FILE.write("\\begin{lstlisting}[language=C++]\n")
    with open(path, "r") as f:
        FILE.write(f.read())
    FILE.write("\\end{lstlisting}\n")

    if two_columns:
        FILE.write("\\end{multicols}\n\n")

    FILE.write("\\hfill\n\n")


def fix_readme(path: Path):
    # check if it has an empty line at the end
    lines = []
    with open(path, "r") as f:
        lines = f.readlines()
        while lines[-1].strip() in ["", "\n"]:
            lines.pop()
    with open(path, "w") as f:
        f.write("".join(lines))


def dfs(path: Path, FILE: Path, level: int = 0):
    printa_section(path, FILE, level)

    endpoint = False

    dirs = path.iterdir()
    dirs = sorted(dirs, key=lambda x: x.name)

    for child in dirs:
        if child.is_dir():
            dfs(child, FILE, level + 1)
        else:
            endpoint = True

    if endpoint:
        if not (path / "README.md").exists():
            raise Exception(f"README.md not found in {path}")
        readme = path / "README.md"

        fix_readme(readme)
        printa_readme(readme, FILE)

        CODIGOS = list(path.glob("*"))
        # pick the files whose name does not match any gitignore regex
        CODIGOS = [x for x in CODIGOS if not is_gitignored(x) and not x.name.endswith(".md")]

        for codigo in CODIGOS:
            printa_codigo(codigo, FILE)
        # FILE.write("\\rule{\\textwidth}{0.4pt}\n\n")


def dfs_readmes(path: Path, FILE: Path, level: int, fullPath: str):
    name = path.name.replace("-", " ")
    if level == 0:
        FILE.write(f"### [{name}]({fullPath})\n\n")
        print(f"\n===== {name} =====\n")
    elif level == 1:
        FILE.write(f"- [{name}]({fullPath})\n\n")
        print(f"- {name}")
    elif level == 2:
        FILE.write(f"    - [{name}]({fullPath})\n\n")
        print(f"  - {name}")
    elif level == 3:
        FILE.write(f"        - [{name}]({fullPath})\n\n")
        print(f"   - {name}")
    elif level == 4:
        FILE.write(f"            - [{name}]({fullPath})\n\n")
        print(f"    - {name}")
    for child in path.iterdir():
        if child.is_dir():
            dfs_readmes(child, FILE, level + 1, fullPath + "/" + child.name)


if __name__ == "__main__":

    if not Path("Codigos").exists():
        raise Exception("Esse script deve ser executado na raiz do repositório.")
    
    global gitignore

    with open(".gitignore", "r") as f:
        gitignore = [gitignore_to_regex(line) for line in f]

    DIR = Path("Codigos")
    ALMANAQUE = Path("LaTeX/Almanaque.tex")
    with open(ALMANAQUE, "w") as f:
        INICIO = Path("LaTeX/INICIO_LATEX.tex")
        printa_arquivo(INICIO, f)

        STL = Path("LaTeX/STL.tex")
        printa_arquivo(STL, f)

        TEORICO = Path("LaTeX/Teorico.tex")
        printa_arquivo(TEORICO, f)

        EXTRA = Path("Codigos/Extra")
        dfs(EXTRA, f, 0)

        for child in DIR.iterdir():
            if child.is_dir() and child.name != "Extra":
                dfs(child, f, 0)
        
        f.write("\\end{document}\n")
    
    clean = True

    if Path("LaTeX/Almanaque.tex").exists():
        os.system("rubber --pdf --inplace LaTeX/Almanaque.tex")
    else:
        raise Exception("Arquivo LaTeX/Almanaque.tex não encontrado.")

    if Path("LaTeX/Almanaque.pdf").exists():
        print("\nPDF gerado com sucesso e salvo em PDF/Almanaque.pdf")
        os.replace("LaTeX/Almanaque.pdf", "PDF/Almanaque.pdf")
        os.replace("LaTeX/Almanaque.tex", "PDF/Almanaque.tex")
    else:
        raise Exception("PDF não foi gerado, ocorreu algum erro.")

    if clean:
        if Path("LaTeX/Almanaque.log").exists():
            os.remove("LaTeX/Almanaque.log")
        if Path("LaTeX/Almanaque.aux").exists():
            os.remove("LaTeX/Almanaque.aux")
        if Path("LaTeX/Almanaque.out").exists():
            os.remove("LaTeX/Almanaque.out")
        if Path("LaTeX/Almanaque.toc").exists():
            os.remove("LaTeX/Almanaque.toc")
        if Path("LaTeX/Almanaque.tex").exists():
            os.remove("LaTeX/Almanaque.tex")
        if Path("LaTeX/Almanaque.rubbercache").exists():
            os.remove("LaTeX/Almanaque.rubbercache")


    README = Path("README.md")
    with open(README, "w") as f:
        printa_arquivo(Path("LaTeX/INICIO_README.md"), f)
        f.write("## Tabela de Conteúdos\n\n")
        for child in DIR.iterdir():
            if child.is_dir():
                dfs_readmes(child, f, 0, "Codigos/" + child.name)
        print("")
        f.write("\n\n")

    print("")

else:
    print("Esse script não deve ser importado, apenas executado.")

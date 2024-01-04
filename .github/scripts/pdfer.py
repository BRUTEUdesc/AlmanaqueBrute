#!/usr/bin/env python3

from pathlib import Path

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
                    dest.write("\\lstinline{")
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
    max_lenght = 60
    two_columns = True
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


def dfs(path: Path, FILE: Path, level: int = 0):
    printa_section(path, FILE, level)

    endpoint = False
    for child in path.iterdir():
        if child.name.endswith(".cpp"):
            endpoint = True

    if endpoint:
        # checks if there is a README.md
        if not (path / "README.md").exists():
            raise Exception(f"README.md not found in {path}")
        readme = path / "README.md"
        printa_readme(readme, FILE)

        CODIGOS = list(path.glob("*.cpp"))

        for codigo in CODIGOS:
            printa_codigo(codigo, FILE)
        # FILE.write("\\rule{\\textwidth}{0.4pt}\n\n")

    for child in path.iterdir():
        if child.is_dir():
            dfs(child, FILE, level + 1)


def get_description(path: Path):
    ret_lines = []
    with open(path, "r") as f:
        append = False
        for line in f.readlines():
            if line.startswith("<!-- DESCRIPTION -->"):
                if append:
                    break
                append = True
            elif append:
                ret_lines.append(line)
    return "".join(ret_lines)

def dfs_readmes(path: Path, FILE: Path, level: int):
    cpp_code = False
    for child in DIR.iterdir():
        if child.is_dir():
            dfs_readmes(child, FILE, level + 1)
        elif child.name.endswith(".cpp"):
            cpp_code = True

    my_name = path.name.replace("-", " ")
    my_readme = path / "README.md"

    if not my_readme.exists():
        my_name.touch()

    with open(my_readme, "w") as f:
        f.write(f"# {my_name}\n\n")
        f.write(get_description(my_readme) + "\n\n")
        if cpp_code:
            f.write("## Códigos\n\n")
            for child in path.iterdir():
                if child.name.endswith(".cpp"):
                    f.write(f"### [{child.name}](./{child.name})\n\n")
                    f.write(get_description(child) + "\n\n")


def update_readmes():
    DIR = Path("Codigos")
    for child in DIR.iterdir():
        if child.is_dir():
            README = child / "README.md"
            with open(README, "w") as readme:
                name = child.name.replace("-", " ")
                readme.write(f"# {name}\n\n")
                for subdir in child.iterdir():
                    if subdir.is_dir():
                        name = subdir.name.replace("-", " ")
                        readme.write(f"## [{name}](./{subdir.name})\n\n")
                        readme.write(get_description(subdir / "README.md") + "\n\n")


if __name__ == "__main__":

    update_readmes()

    ALMANAQUE = Path("LaTeX/Almanaque.tex")
    with open(ALMANAQUE, "w") as f:
        INICIO = Path(".github/files/INICIO_LATEX.tex")
        printa_arquivo(INICIO, f)

        DIR = Path("Codigos")

        for child in DIR.iterdir():
            if child.is_dir():
                dfs(child, f, 0)

        f.write("\\end{document}\n")


else:
    print("Esse script não deve ser importado, apenas executado.")
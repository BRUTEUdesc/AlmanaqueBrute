#!/usr/bin/env python3

# this script will generate a latex file with all the cpp code in the repo

import os
from pathlib import Path

def printa_arquivo(path: Path, FILE: Path):
    with open(path, "r") as f:
        FILE.write(f.read())

def printa_readme(path: Path, FILE: Path, level: int):
    with open(path, "r") as f:
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
                    if line[i] in ['%', '&', '~', '_'] and not in_math:
                        dest.write('\\')
                    dest.write(line[i])
                i += 1
            dest.write("\n")

        in_code = False
        in_list = False
        first_line = True

        lines = f.readlines()

        while not lines[0].startswith("#"):
            lines.pop(0)
        
        name = lines[0][1:].strip()

        if name.find('[') != -1:
            name = name[name.find('[') + 1:name.find(']')]
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
    FILE.write("\\begin{lstlisting}[language=C++]\n")
    with open(path, "r") as f:
        FILE.write(f.read())
    FILE.write("\\end{lstlisting}\n")

    FILE.write("\\hfill\n\n")


def dfs(path: Path, FILE: Path, level: int = 0):
    tem_readme = False
    for child in path.iterdir():
        if child.name == "README.md":
            tem_readme = True

    if tem_readme:
        readme = path / "README.md"

        printa_readme(readme, FILE, level)

        CODIGOS = list(path.glob("*.cpp"))
        for codigo in CODIGOS:
            printa_codigo(codigo, FILE)
        FILE.write("\\rule{\\textwidth}{0.4pt}\n\n")

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


if __name__ == "__main__":

    ALMANAQUE = Path("LaTeX/Almanaque.tex")

    with open(ALMANAQUE, "w") as f:

        INICIO = Path(".github/files/INICIO_LATEX.tex")
        printa_arquivo(INICIO, f)

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
        
        for child in DIR.iterdir():
            if child.is_dir():
                dfs(child, f, 0)

        f.write("\\end{document}\n")


else:
    print("Esse script não deve ser importado, apenas executado.")
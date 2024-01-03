#!/usr/bin/env python3

# this script will generate a latex file with all the cpp code in the repo

import os
from pathlib import Path

def printa_arquivo(path: Path, FILE: Path):
    with open(path, "r") as f:
        FILE.write(f.read())

def printa_readme(path: Path, FILE: Path, level: int):
    with open(path, "r") as f:
        in_code = False
        first_line = True
        for line in f.readlines():
            if line.startswith("```"):
                if in_code:
                    FILE.write("\\end{lstlisting}\n\n")
                    in_code = False
                else:  
                    FILE.write("\\begin{lstlisting}[language=C++]\n")
                    in_code = True

            elif in_code: 
                FILE.write(line)

            elif (line.startswith("#")) and first_line:
                it = 0
                while (line[it] == "#" or line[it] == " "):
                    it += 1
                name = line[it:-1]
                if name[0] == '[':
                    name = name[1:name.find(']')]

                if level == 1:
                    FILE.write(f"\\subsection{{{name}}}\n\n")
                elif level == 2:
                    FILE.write(f"\\subsubsection{{{name}}}\n\n")

                first_line = False

            elif "English" in line:
                pass

            else:
                in_inline_code = False
                for i in range(len(line)):
                    if line[i] == '`':
                        if in_inline_code:
                            FILE.write("}")
                        else:
                            FILE.write("\\lstinline{")
                        in_inline_code = not in_inline_code
                    else:
                        # if line[i] in ['_', '&', '%', '#', '{', '}']:
                        #     FILE.write('\\')
                        if line[i] in ['_', '%', '#']:
                            FILE.write('\\')
                        FILE.write(line[i])

        FILE.write("\n")

def printa_codigo(path: Path, FILE: Path):
    max_width = 55
    two_columns = True

    with open(path, "r") as f:
        lines = f.readlines()
        for line in lines:
            if len(line) > max_width:
                two_columns = False
                break

    if two_columns:
        FILE.write("\\begin{multicols}{2}\n")

    FILE.write("\\begin{lstlisting}[language=C++]\n")
    with open(path, "r") as f:
        FILE.write(f.read())
    FILE.write("\\end{lstlisting}\n")

    if two_columns:
        FILE.write("\\end{multicols}\n")
    FILE.write("\n")


def printa_section(section: str, FILE: Path):
    FILE.write("\\newpage\n")

    FILE.write("%%%%%%\n")
    for i in range(2):
        FILE.write("%\n")
    FILE.write(f"% {section}\n")
    for i in range(2):
        FILE.write("%\n")
    FILE.write("%%%%%%\n\n")

    FILE.write(f"\\section{{{section}}}\n\n")

def printa_subsection(subsection: str, FILE: Path, level: int):
    if level == 1:
        FILE.write(f"\\subsection{{{subsection}}}\n\n")
    elif level == 2:
        FILE.write(f"\\subsubsection{{{subsection}}}\n\n")

def dfs(path: Path, FILE: Path, level: int = 0):
    tem_readme = False
    for child in path.iterdir():
        if child.is_dir():
            dfs(child, FILE, level + 1)
        elif child.name.endswith(".md"):
            tem_readme = True

    if tem_readme:
        # printa_subsection(path.name, FILE, level)
        
        READMES = [x for x in path.glob("*.md") if not "en" in x.name]
        for readme in READMES:
            printa_readme(readme, FILE, level)

        CODIGOS = list(path.glob("*.cpp"))
        for codigo in CODIGOS:
            printa_codigo(codigo, FILE)


if __name__ == "__main__":

    ALMANAQUE = Path("LaTeX/Almanaque.tex")

    with open(ALMANAQUE, "w") as f:

        INICIO = Path(".github/files/INICIO_LATEX.tex")
        printa_arquivo(INICIO, f)

        DIR = Path("Codigos")

        for child in DIR.iterdir():
            if child.is_dir():
                printa_section(child.name, f)
                dfs(child, f)

        f.write("\\end{document}\n")


else:
    print("Esse script não deve ser importado, apenas executado.")
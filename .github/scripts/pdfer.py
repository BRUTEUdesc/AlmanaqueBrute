
import os
from pathlib import Path

from markdown import markdown

def output_readme(file: Path):
    s = file.open().read().replace("*Read in [English](README.en.md)*", "").replace("_Read in [English](README.en.md)_", "")
    if str(file).count("/") == 2:
        # print(s)
        # while s.startswith("\n"):
        #     s = s[1:]
        # s = "#" + s
        new_s = ''
        for line in s.splitlines():
            if line.startswith("# "):
                line = "#" + line + '\n\n'
                # print("132-   "+line)
            new_s += line + '\n'
        s = new_s
    if str(file).count("/") == 1:
        s = "<div style=\"page-break-after: always;\"></div>\n" + s
    return s

def output_code(file: Path):
    formated_text = "```c++\n" + file.open().read() + "\n```\n"
    return formated_text


def output_dir(dir_path: Path):
    if (dir_path / "README.md").is_file():
        yield "-----"
        yield output_readme(dir_path / "README.md")
    for path in dir_path.iterdir():
        if path.name.startswith('.'):
            pass
        if path.is_dir():
            yield from output_dir(path)
        elif path.name.endswith('.cpp'):
            yield f"### *Implementação {path.stem}*:".title().replace('_', " ")
            yield output_code(path)
        
                

if __name__ == "__main__":
    md = output_dir(Path('.'))
    html = markdown("\n".join(md), extensions=["fenced_code"])
    with open("Almanaque.html", "w") as f:
        f.write(html)
        f.close()
    print("Created Almanaque.html")
else:
    print("Function not called correctly, please try again.")
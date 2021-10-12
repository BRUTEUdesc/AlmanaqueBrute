
import os
from pathlib import Path

from markdown import markdown

def output_readme(file: Path):
    return file.open().read()


def output_code(file: Path):
    formated_text = "``` python3\n" + file.open().read() + "```\n"
    return formated_text


def output_dir(dir_path: Path):
    if (dir_path / "README.md").is_file():
        yield output_readme(dir_path / "README.md")
    for path in dir_path.iterdir():
        if path.name.startswith('.'):
            pass
        if path.is_dir():
            yield from output_dir(path)
        elif path.name.endswith('.cpp'):
            yield output_code(path)
                

if __name__ == "__main__":
    md = output_dir(Path('.'))
    html = markdown("\n".join(md))
    with open("Almanaque.html", "w") as f:
        f.write(html)
        f.close()
else:
    print("Function not called correctly, please try again.")
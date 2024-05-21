# Almanaque BRUTE

Repositório de códigos para programação competitiva do **BRUTE UDESC**.

### Pasta `Codigos`

Todas as implementações estão nesta pasta.

### Pasta `LaTeX`

Aqui estão os arquivos `.tex` que compõem o Almanaque.

O primeiro arquivo é o `INICIO_README.md`, que é convertido para o `README.md` do repositório.

O `INICIO_LATEX.tex` é o início do arquivo `.tex` do Almanaque, ele contém as principais configurações e o início do documento.

Os arquivos `STL.tex`, `Templates.tex` e `Teorico.tex` são os arquivos `tex` dos primeiros capítulos do Almanaque.

### Pasta `PDF`

Aqui está o `.pdf` do Almanaque.

## Para fazer contribuições

Faça um fork do repositório e depois faça um Pull Request para mergear.

Os códigos devem seguir a formatação especificada no arquivo `.clang-format`, para executar o clang-format usando esse arquivo como entrada digite:

```
clang-format -i -style=FILE Codigos/.../a.cpp
```

Para executar o clang-format em todos os arquivos `.cpp` da pasta `Codigos` digite:

```
find Codigos/ -type f -name "*.cpp" -exec clang-format -style=FILE -i {} \;
```

Opcional: clone o repositório e execute o comando `.github/scripts/git-pre-commit-format install`, isso vai instalar um hook que vai executar o clang-format a cada commit.

Após qualquer alteração, basta executar o arquivo `.github/scripts/pdfer.py` para atualizar o PDF e o README principal. *TODO: execução automática do pdfer.py.*

**Obs: antes de rodar o `pdfer.py`, execute os seguintes comandos para instalar o latex e as dependências:**

```
sudo apt install texlive-full
sudo apt install rubber
```

Execute o `pdfer.py` com o comando:

```
python3 .github/scripts/pdfer.py
```

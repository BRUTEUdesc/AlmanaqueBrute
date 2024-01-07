# Almanaque BRUTE

Repositório de códigos para programação competitiva do BRUTE UDESC.

### Pasta `Codigos`

Todas as implementações estão nessa pasta.

### Pasta `LaTeX`

Aqui estão os arquivos `.tex`.

Aqui também estão os arquivos `INICIO_README.md` e `INICIO_LATEX.tex`, que são usados como cabeçalho para os arquivos `README.md` e `almanaque.tex`, respectivamente. Se quiser alterar o README ou as configurações do latex, edite sempre esses arquivos.

Após qualquer alteração nos códigos ou nos arquivos `INICIO*`, basta executar o arquivo `.github/scripts/pdfer.py`. TODO: atualização automática.

OBS: Antes de rodar o `pdfer.py`, rode os seguintes comandos para instalar o latex e as dependências:

```
sudo apt install texlive-full
sudo apt install rubber
```

### Pasta `PDF`

Aqui está o `.pdf` do Almanaque.

## Para fazer contribuições

Clone o repositório, crie uma nova branch e depois faça um Pull Request para mergear.

Os códigos devem seguir a formatação especificada no arquivo `.clang-format`, para executar o clang-format usando esse arquivo como entrada digite:

```
clang-format -i -style=FILE Codigos/.../a.cpp
```

Para executar o clang-format em todos os arquivos `.cpp` da pasta `Codigos` digite:

```
find Codigos/ -type f -name "*.cpp" -exec clang-format -style=file -i {} \;
```

Opcional: clone o repositório e execute o comando `.github/scripts/git-pre-commit-format install`, isso vai instalar um hook que vai executar o clang-format a cada commit.

Atualize o PDF com o comando:

```
python3 .github/scripts/pdfer.py
```

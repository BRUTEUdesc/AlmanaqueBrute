# Almanaque BRUTE

Repositório de códigos para programação competitiva do BRUTE UDESC.

### Pasta `Codigos`

Todas as implementações estão nessa pasta.

### Pasta `LaTeX`

Aqui estão os arquivos `.tex`.

Aqui também estão os arquivos `INICIO_README.md` e `INICIO_LATEX.tex`, que são usados como cabeçalho para os arquivos `README.md` e `almanaque.tex`, respectivamente. Se quiser alterar o README ou as configurações do latex, edite sempre esses arquivos.

### Pasta `PDF`

Aqui está o `.pdf` do Almanaque.

### Pasta `Theoretical`

Aqui está um arquivo `.tex` com teoremas, fórmulas, e informações úteis em contest.

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

Após qualquer alteração nos códigos ou nos arquivos `INICIO*`, basta executar o arquivo `.github/scripts/pdfer.py` para atualizar o PDF e o README principal. *TODO: execução automática do pdfer.py.*

**Obs: antes de rodar o `pdfer.py`, execute os seguintes comandos para instalar o latex e as dependências:**

```
sudo apt install texlive-full
sudo apt install rubber
```

Execute o `pdfer.py` com o comando:

```
python3 .github/scripts/pdfer.py
```

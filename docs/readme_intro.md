# Almanaque BRUTE

Repositório de códigos e notas para programação competitiva do **BRUTE UDESC**.

## Estrutura do repositório

- `Codigos/` – Implementações em C++ organizadas por tema. Cada diretório possui um `README.md` com notas rápidas e o(s) arquivo(s) `.cpp` correspondentes.
- `LaTeX/` – Fontes do Almanaque. O arquivo `main.tex` é gerado automaticamente a partir da estrutura em `chapters/<prefixo>-<tema>/index.tex`. As configurações ficam em `preamble.tex` e na pasta `configs/`.
- `PDF/` – Resultado compilado (`Almanaque.pdf`) e o `main.tex` utilizado na última geração.
- `docs/readme_intro.md` – Template usado pelo script para atualizar este README (não editar `README.md` diretamente).
- `.github/` – Scripts auxiliares (`.github/scripts/pdfer.py`) e workflows que automatizam a geração do PDF.

## Como contribuir

1. Faça fork e crie uma branch com seu tópico.
2. Formate os arquivos C++ com o `.clang-format` do repositório:
   ```
   clang-format -i -style=FILE Codigos/.../arquivo.cpp
   ```
   Para aplicar em todos os `.cpp`:
   ```
   find Codigos/ -type f -name "*.cpp" -exec clang-format -style=FILE -i {} \;
   ```
3. Abra o Pull Request descrevendo as mudanças relevantes. O PDF e o `README.md` serão atualizados automaticamente via GitHub Actions após o merge.

## Atualização do README

Sempre que o `pdfer.py` roda (localmente ou no GitHub Actions) ele reescreve o README com base no template em `docs/readme_intro.md` e na árvore de diretórios em `Codigos/`. Se precisar alterar instruções permanentes, edite `docs/readme_intro.md` e gere novamente o PDF (ou execute `python3 .github/scripts/pdfer.py`) para refletir no `README.md`.

## Geração do PDF

### Pipeline automatizada (GitHub Actions)

O workflow `.github/workflows/generate_almanaque_pdf.yml` é a forma padrão de atualizar o PDF. Ele roda a cada push na branch `main` (ou manualmente via *workflow dispatch*), recompila o Almanaque com as dependências LaTeX necessárias e abre um PR automático (`chore: Atualiza o PDF`) com o PDF e o `main.tex` atualizados.

### Execução com container (opcional)

Para gerar localmente com o mesmo stack de dependências do CI:

```
make pdf
```

O comando constrói (ou reaproveita) a imagem `almanaque-latex:latest`, monta o repositório em `/workspace` e roda `.github/scripts/pdfer.py`. Variáveis úteis:

- `CONTAINER_ENGINE` (padrão `podman`) – altere para `docker` se preferir.
- `BASE_IMAGE` – imagem base usada no build (padrão `python:3.11-slim`).
- `LATEX_IMAGE` – nome/tag da imagem local.

Outros alvos disponíveis:

```
make latex-image   # só constrói/atualiza a imagem
make container-shell  # abre um shell interativo dentro da imagem
make generate      # roda o pdfer.py na máquina local (requer LaTeX instalado)
```

### Execução local sem container

Se preferir instalar as dependências manualmente:

```
sudo apt install texlive-latex-base texlive-latex-recommended \
                 texlive-latex-extra texlive-fonts-recommended \
                 texlive-lang-portuguese latexmk lmodern cm-super rubber
python3 .github/scripts/pdfer.py
```

O script regenera `LaTeX/main.tex`, compila `Almanaque.pdf` e atualiza o README com a nova árvore de conteúdos.

## Estrutura dos capítulos LaTeX

- A pasta `LaTeX/chapters/` é organizada por tema (`NN-nome/index.tex`), onde `NN` controla a ordem no PDF.
- Cada `index.tex` do capítulo usa `\input{...}` para incluir as seções do tema.
- Arquivos de configuração comuns:
  - `configs/packages.tex` – pacotes LaTeX, geometria da página e macros globais.
  - `configs/titlesec.tex` – espaçamentos compactos de títulos.
  - `configs/listings.tex` – estilo dos blocos de código.

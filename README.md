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

## Tabela de Conteúdos

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)
  - [DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU)
  - [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)
  - [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)
  - [DSU Rollback Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback-Bipartido)
  - [Offline DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/Offline-DSU)
- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)
  - [Fenwick](Codigos/Estruturas-de-Dados/Fenwick-Tree/Fenwick)
  - [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree/Kd-Fenwick-Tree)
- [Implicit Treap](Codigos/Estruturas-de-Dados/Implicit-Treap)
- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)
- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)
- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree)
  - [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree)
  - [Merge Sort Tree Update](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree-Update)
- [Operation Deque](Codigos/Estruturas-de-Dados/Operation-Deque)
- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)
- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)
- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)
- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)
  - [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)
  - [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)
  - [Segment Tree Beats](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats)
  - [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)
  - [Segment Tree Iterativa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Iterativa)
  - [Segment Tree Kadane](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadane)
  - [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)
  - [Segment Tree Lazy Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy-Esparsa)
  - [Segment Tree PA](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-PA)
  - [Segment Tree Persistente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persistente)
- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)
  - [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)
  - [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)
- [Treap](Codigos/Estruturas-de-Dados/Treap)
- [XOR Trie](Codigos/Estruturas-de-Dados/XOR-Trie)
### [Extra](Codigos/Extra)

- [CPP](Codigos/Extra/CPP)
- [Debug](Codigos/Extra/Debug)
- [Random](Codigos/Extra/Random)
- [Run](Codigos/Extra/Run)
- [Stress Test](Codigos/Extra/Stress-Test)
- [Unordered Custom Hash](Codigos/Extra/Unordered-Custom-Hash)
- [Vim](Codigos/Extra/Vim)
### [Geometria](Codigos/Geometria)

- [Convex Hull](Codigos/Geometria/Convex-Hull)
### [Grafos](Codigos/Grafos)

- [2 SAT](Codigos/Grafos/2-SAT)
- [Binary Lifting](Codigos/Grafos/Binary-Lifting)
  - [Binary Lifting LCA](Codigos/Grafos/Binary-Lifting/Binary-Lifting-LCA)
  - [Binary Lifting Query](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query)
  - [Binary Lifting Query 2](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-2)
  - [Binary Lifting Query Aresta](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-Aresta)
- [Block Cut Tree](Codigos/Grafos/Block-Cut-Tree)
- [Caminho Euleriano](Codigos/Grafos/Caminho-Euleriano)
  - [Caminho Euleriano Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Direcionado)
  - [Caminho Euleriano Nao Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Nao-Direcionado)
- [Centro e Diametro](Codigos/Grafos/Centro-e-Diametro)
- [Centroids](Codigos/Grafos/Centroids)
  - [Centroid](Codigos/Grafos/Centroids/Centroid)
  - [Centroid Decomposition](Codigos/Grafos/Centroids/Centroid-Decomposition)
- [Ciclos](Codigos/Grafos/Ciclos)
  - [Find Cycle](Codigos/Grafos/Ciclos/Find-Cycle)
  - [Find Negative Cycle](Codigos/Grafos/Ciclos/Find-Negative-Cycle)
- [Fluxo](Codigos/Grafos/Fluxo)
- [HLD](Codigos/Grafos/HLD)
  - [HLD Aresta](Codigos/Grafos/HLD/HLD-Aresta)
  - [HLD Vértice](Codigos/Grafos/HLD/HLD-Vértice)
- [Inverse Graph](Codigos/Grafos/Inverse-Graph)
- [Kosaraju](Codigos/Grafos/Kosaraju)
- [Kruskal](Codigos/Grafos/Kruskal)
- [LCA](Codigos/Grafos/LCA)
- [Matching](Codigos/Grafos/Matching)
  - [Hungaro](Codigos/Grafos/Matching/Hungaro)
- [Pontes](Codigos/Grafos/Pontes)
  - [Componentes Aresta Biconexas](Codigos/Grafos/Pontes/Componentes-Aresta-Biconexas)
  - [Pontes](Codigos/Grafos/Pontes/Pontes)
- [Pontos de Articulacao](Codigos/Grafos/Pontos-de-Articulacao)
- [Shortest Paths](Codigos/Grafos/Shortest-Paths)
  - [01 BFS](Codigos/Grafos/Shortest-Paths/01-BFS)
  - [BFS](Codigos/Grafos/Shortest-Paths/BFS)
  - [Bellman Ford](Codigos/Grafos/Shortest-Paths/Bellman-Ford)
  - [Dial](Codigos/Grafos/Shortest-Paths/Dial)
  - [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)
  - [Floyd Warshall](Codigos/Grafos/Shortest-Paths/Floyd-Warshall)
  - [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)
- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)
- [Virtual Tree](Codigos/Grafos/Virtual-Tree)
### [Matemática](Codigos/Matemática)

- [Continued Fractions](Codigos/Matemática/Continued-Fractions)
- [Convolução](Codigos/Matemática/Convolução)
  - [AND Convolution](Codigos/Matemática/Convolução/AND-Convolution)
  - [Dirichlet Convolution](Codigos/Matemática/Convolução/Dirichlet-Convolution)
    - [Dirichlet Convolution](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Convolution)
    - [Dirichlet Convolution Prefix](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Convolution-Prefix)
    - [Dirichlet Inverse Prefix](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Inverse-Prefix)
  - [GCD Convolution](Codigos/Matemática/Convolução/GCD-Convolution)
  - [LCM Convolution](Codigos/Matemática/Convolução/LCM-Convolution)
  - [OR Convolution](Codigos/Matemática/Convolução/OR-Convolution)
  - [Subset Convolution](Codigos/Matemática/Convolução/Subset-Convolution)
  - [XOR Convolution](Codigos/Matemática/Convolução/XOR-Convolution)
- [Discrete Root](Codigos/Matemática/Discrete-Root)
- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)
  - [Gauss](Codigos/Matemática/Eliminação-Gaussiana/Gauss)
  - [Gauss Mod 2](Codigos/Matemática/Eliminação-Gaussiana/Gauss-Mod-2)
- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)
- [FFT](Codigos/Matemática/FFT)
- [Fatoração e Primos](Codigos/Matemática/Fatoração-e-Primos)
  - [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo)
    - [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo)
    - [Crivo Linear](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo-Linear)
  - [Divisores](Codigos/Matemática/Fatoração-e-Primos/Divisores)
    - [Divisores Naive](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Naive)
    - [Divisores Rápido](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Rápido)
  - [Fatores](Codigos/Matemática/Fatoração-e-Primos/Fatores)
    - [Fatoração Naive](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Naive)
    - [Fatoração Rápida](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Rápida)
  - [Pollard Rho](Codigos/Matemática/Fatoração-e-Primos/Pollard-Rho)
  - [Teste Primalidade](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade)
    - [Miller Rabin](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Miller-Rabin)
    - [Teste Primalidade Naive](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Teste-Primalidade-Naive)
- [Floor Values](Codigos/Matemática/Floor-Values)
- [Floor and Mod Sum of Arithmetic Progressions](Codigos/Matemática/Floor-and-Mod-Sum-of-Arithmetic-Progressions)
- [GCD](Codigos/Matemática/GCD)
- [Inverso Modular](Codigos/Matemática/Inverso-Modular)
- [NTT](Codigos/Matemática/NTT)
  - [NTT](Codigos/Matemática/NTT/NTT)
  - [NTT Big Modulo](Codigos/Matemática/NTT/NTT-Big-Modulo)
  - [Taylor Shift](Codigos/Matemática/NTT/Taylor-Shift)
- [Polinomios](Codigos/Matemática/Polinomios)
- [SMAWCK](Codigos/Matemática/SMAWCK)
- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)
- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)
- [XOR Gauss](Codigos/Matemática/XOR-Gauss)
### [Paradigmas](Codigos/Paradigmas)

- [All Submasks](Codigos/Paradigmas/All-Submasks)
- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)
- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)
- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)
- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)
- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)
- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)
- [Mo](Codigos/Paradigmas/Mo)
  - [Mo](Codigos/Paradigmas/Mo/Mo)
  - [Mo Update](Codigos/Paradigmas/Mo/Mo-Update)
### [Primitivas](Codigos/Primitivas)

- [Modular Int](Codigos/Primitivas/Modular-Int)
- [Ponto 2D](Codigos/Primitivas/Ponto-2D)
### [String](Codigos/String)

- [Aho Corasick](Codigos/String/Aho-Corasick)
- [EertreE](Codigos/String/EertreE)
- [Hashing](Codigos/String/Hashing)
  - [Hashing](Codigos/String/Hashing/Hashing)
  - [Hashing Dinâmico](Codigos/String/Hashing/Hashing-Dinâmico)
- [Lyndon](Codigos/String/Lyndon)
- [Manacher](Codigos/String/Manacher)
- [Patricia Tree](Codigos/String/Patricia-Tree)
- [Prefix Function KMP](Codigos/String/Prefix-Function-KMP)
  - [Automato KMP](Codigos/String/Prefix-Function-KMP/Automato-KMP)
  - [KMP](Codigos/String/Prefix-Function-KMP/KMP)
- [Suffix Array](Codigos/String/Suffix-Array)
- [Suffix Automaton](Codigos/String/Suffix-Automaton)
- [Suffix Tree](Codigos/String/Suffix-Tree)
- [Trie](Codigos/String/Trie)
- [Z function](Codigos/String/Z-function)


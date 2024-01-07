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

Opcional: clone o repositório e execute o comando `.github/scripts/git-pre-commit-format install`, isso vai instalar um hook que vai executar o clang-format a cada commit.

## Tabela de Conteúdos

### [Matemática](Codigos/Matemática)

- [Sum of floor(n div i)](Codigos/Matemática/Sum-of-floor(n-div-i))

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

- [FFT](Codigos/Matemática/FFT)

- [Primos](Codigos/Matemática/Primos)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)

- [NTT](Codigos/Matemática/NTT)

- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)

- [Fatoração](Codigos/Matemática/Fatoração)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [GCD](Codigos/Matemática/GCD)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

- [MergeSort Tree](Codigos/Estruturas-de-Dados/MergeSort-Tree)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

    - [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

    - [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

    - [DSU Simples](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Simples)

    - [DSU Completo](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Completo)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

    - [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

    - [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

- [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Kd-Fenwick-Tree)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

    - [Segment Tree Beats Max And Sum Update](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats-Max-And-Sum-Update)

    - [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

    - [Segment Tree Beats Max Update](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats-Max-Update)

    - [Segment Tree Kadani](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadani)

    - [Segment Tree Persisente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persisente)

    - [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

    - [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

    - [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

### [Grafos](Codigos/Grafos)

- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

    - [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

    - [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)

- [2 SAT](Codigos/Grafos/2-SAT)

- [Fluxo](Codigos/Grafos/Fluxo)

- [Kruskal](Codigos/Grafos/Kruskal)

- [Graph Center](Codigos/Grafos/Graph-Center)

- [Bridge](Codigos/Grafos/Bridge)

- [HLD](Codigos/Grafos/HLD)

- [Matching](Codigos/Grafos/Matching)

    - [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

- [LCA](Codigos/Grafos/LCA)

### [String](Codigos/String)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [Trie](Codigos/String/Trie)

- [Suffix Array](Codigos/String/Suffix-Array)

- [Manacher](Codigos/String/Manacher)

- [Patricia Tree](Codigos/String/Patricia-Tree)

- [Prefix Function](Codigos/String/Prefix-Function)

- [Hashing](Codigos/String/Hashing)

- [Lyndon](Codigos/String/Lyndon)

### [Paradigmas](Codigos/Paradigmas)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

- [Mo](Codigos/Paradigmas/Mo)




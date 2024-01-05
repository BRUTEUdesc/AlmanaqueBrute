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
## Tabela de Conteúdos

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

    - [DSU Completo](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Completo)

    - [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

    - [DSU Simples](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Simples)

    - [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

    - [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

    - [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

    - [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

    - [Segment Tree Beats Max And Sum Update](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats-Max-And-Sum-Update)

    - [Segment Tree Beats Max Update](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats-Max-Update)

    - [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

    - [Segment Tree Persisente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persisente)

    - [Segment Tree Kadani](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadani)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Kd-Fenwick-Tree)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [MergeSort Tree](Codigos/Estruturas-de-Dados/MergeSort-Tree)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

    - [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

    - [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

### [Grafos](Codigos/Grafos)

- [Matching](Codigos/Grafos/Matching)

    - [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Stoer–Wagner minimum cut](Codigos/Grafos/Stoer–Wagner-minimum-cut)

- [LCA](Codigos/Grafos/LCA)

- [HLD](Codigos/Grafos/HLD)

- [Kruskal](Codigos/Grafos/Kruskal)

- [Bridge](Codigos/Grafos/Bridge)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

    - [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

    - [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

- [Fluxo](Codigos/Grafos/Fluxo)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)

- [2 SAT](Codigos/Grafos/2-SAT)

- [Graph Center](Codigos/Grafos/Graph-Center)

### [String](Codigos/String)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [Patricia Tree](Codigos/String/Patricia-Tree)

- [Prefix Function](Codigos/String/Prefix-Function)

- [Hashing](Codigos/String/Hashing)

- [Trie](Codigos/String/Trie)

- [Manacher](Codigos/String/Manacher)

- [Lyndon](Codigos/String/Lyndon)

- [Suffix Array](Codigos/String/Suffix-Array)

### [Paradigmas](Codigos/Paradigmas)

- [Mo](Codigos/Paradigmas/Mo)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

### [Matemática](Codigos/Matemática)

- [Sum of floor(n div i)](Codigos/Matemática/Sum-of-floor(n-div-i))

- [Primos](Codigos/Matemática/Primos)

- [NTT](Codigos/Matemática/NTT)

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

- [GCD](Codigos/Matemática/GCD)

- [Fatoração](Codigos/Matemática/Fatoração)

- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)

- [FFT](Codigos/Matemática/FFT)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)




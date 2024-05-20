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
## Tabela de Conteúdos

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

    - [Fenwick](Codigos/Estruturas-de-Dados/Fenwick-Tree/Fenwick)

    - [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree/Kd-Fenwick-Tree)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

    - [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

    - [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

    - [Segment Tree Beats Max Update](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats-Max-Update)

    - [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

    - [Segment Tree Lazy Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy-Esparsa)

    - [Segment Tree Beats Max And Sum Update](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats-Max-And-Sum-Update)

    - [Segment Tree Persisente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persisente)

    - [Segment Tree Kadane](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadane)

    - [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

    - [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

    - [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree)

    - [Merge Sort Tree Update](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree-Update)

    - [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

    - [DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU)

    - [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

    - [DSU Rollback Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback-Bipartido)

    - [Offline DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/Offline-DSU)

    - [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

### [Primitivas](Codigos/Primitivas)

- [Modular Int](Codigos/Primitivas/Modular-Int)

- [Ponto 2D](Codigos/Primitivas/Ponto-2D)

### [Geometria](Codigos/Geometria)

- [Convex Hull](Codigos/Geometria/Convex-Hull)

### [Extra](Codigos/Extra)

- [Vim](Codigos/Extra/Vim)

- [Unordered Custom Hash](Codigos/Extra/Unordered-Custom-Hash)

- [Debug](Codigos/Extra/Debug)

- [Stress Test](Codigos/Extra/Stress-Test)

- [Run](Codigos/Extra/Run)

- [Random](Codigos/Extra/Random)

- [CPP](Codigos/Extra/CPP)

### [Grafos](Codigos/Grafos)

- [Matching](Codigos/Grafos/Matching)

    - [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Kruskal](Codigos/Grafos/Kruskal)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

    - [Binary Lifting LCA](Codigos/Grafos/Binary-Lifting/Binary-Lifting-LCA)

    - [Binary Lifting Query 2](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-2)

    - [Binary Lifting Query Aresta](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-Aresta)

    - [Binary Lifting Query](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query)

- [Pontes](Codigos/Grafos/Pontes)

- [LCA](Codigos/Grafos/LCA)

- [Centro e Diametro](Codigos/Grafos/Centro-e-Diametro)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

    - [Belmann Ford](Codigos/Grafos/Shortest-Paths/Belmann-Ford)

    - [01 BFS](Codigos/Grafos/Shortest-Paths/01-BFS)

    - [Floyd Warshall](Codigos/Grafos/Shortest-Paths/Floyd-Warshall)

    - [BFS](Codigos/Grafos/Shortest-Paths/BFS)

    - [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

    - [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

- [2 SAT](Codigos/Grafos/2-SAT)

- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)

- [Pontos de Articulacao](Codigos/Grafos/Pontos-de-Articulacao)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)

- [HLD](Codigos/Grafos/HLD)

- [Fluxo](Codigos/Grafos/Fluxo)

### [Paradigmas](Codigos/Paradigmas)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [Mo](Codigos/Paradigmas/Mo)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

### [Matemática](Codigos/Matemática)

- [GCD](Codigos/Matemática/GCD)

- [FFT](Codigos/Matemática/FFT)

- [NTT](Codigos/Matemática/NTT)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

    - [Gauss](Codigos/Matemática/Eliminação-Gaussiana/Gauss)

    - [Gauss Mod 2](Codigos/Matemática/Eliminação-Gaussiana/Gauss-Mod-2)

- [Sum of floor (n div i)](Codigos/Matemática/Sum-of-floor-(n-div-i))

- [Fatoração](Codigos/Matemática/Fatoração)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

- [Primos](Codigos/Matemática/Primos)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)

- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)

### [String](Codigos/String)

- [Trie](Codigos/String/Trie)

- [Prefix Function KMP](Codigos/String/Prefix-Function-KMP)

    - [Automato KMP](Codigos/String/Prefix-Function-KMP/Automato-KMP)

    - [KMP](Codigos/String/Prefix-Function-KMP/KMP)

- [Patricia Tree](Codigos/String/Patricia-Tree)

- [Manacher](Codigos/String/Manacher)

- [Lyndon](Codigos/String/Lyndon)

- [Suffix Array](Codigos/String/Suffix-Array)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [Z function](Codigos/String/Z-function)

- [Hashing](Codigos/String/Hashing)

    - [Hashing Dinâmico](Codigos/String/Hashing/Hashing-Dinâmico)

    - [Hashing](Codigos/String/Hashing/Hashing)




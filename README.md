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

Aqui está o `.tex` do Almanaque e sua versão compilada em `.pdf`.

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

### [Matemática](Codigos/Matemática)

- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)

- [GCD](Codigos/Matemática/GCD)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)

- [Convolução](Codigos/Matemática/Convolução)

	- [Subset Convolution](Codigos/Matemática/Convolução/Subset-Convolution)

	- [LCM Convolution](Codigos/Matemática/Convolução/LCM-Convolution)

	- [OR Convolution](Codigos/Matemática/Convolução/OR-Convolution)

	- [AND Convolution](Codigos/Matemática/Convolução/AND-Convolution)

	- [GCD Convolution](Codigos/Matemática/Convolução/GCD-Convolution)

	- [XOR Convolution](Codigos/Matemática/Convolução/XOR-Convolution)

- [Floor Values](Codigos/Matemática/Floor-Values)

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

	- [Gauss Mod 2](Codigos/Matemática/Eliminação-Gaussiana/Gauss-Mod-2)

	- [Gauss](Codigos/Matemática/Eliminação-Gaussiana/Gauss)

- [FFT](Codigos/Matemática/FFT)

- [Polinomios](Codigos/Matemática/Polinomios)

- [XOR Gauss](Codigos/Matemática/XOR-Gauss)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [NTT](Codigos/Matemática/NTT)

	- [NTT Big Modulo](Codigos/Matemática/NTT/NTT-Big-Modulo)

	- [Taylor Shift](Codigos/Matemática/NTT/Taylor-Shift)

	- [NTT](Codigos/Matemática/NTT/NTT)

- [Fatoração e Primos](Codigos/Matemática/Fatoração-e-Primos)

	- [Teste Primalidade](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade)

		- [Miller Rabin](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Miller-Rabin)

		- [Teste Primalidade Naive](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Teste-Primalidade-Naive)

	- [Divisores](Codigos/Matemática/Fatoração-e-Primos/Divisores)

		- [Divisores Naive](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Naive)

		- [Divisores Rápido](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Rápido)

	- [Fatores](Codigos/Matemática/Fatoração-e-Primos/Fatores)

		- [Fatoração Rápida](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Rápida)

		- [Fatoração Naive](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Naive)

	- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo)

		- [Crivo Linear](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo-Linear)

		- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo)

	- [Pollard Rho](Codigos/Matemática/Fatoração-e-Primos/Pollard-Rho)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

### [Grafos](Codigos/Grafos)

- [Centro e Diametro](Codigos/Grafos/Centro-e-Diametro)

- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)

- [Block Cut Tree](Codigos/Grafos/Block-Cut-Tree)

- [Centroids](Codigos/Grafos/Centroids)

	- [Centroid Decomposition](Codigos/Grafos/Centroids/Centroid-Decomposition)

	- [Centroid](Codigos/Grafos/Centroids/Centroid)

- [Pontos de Articulacao](Codigos/Grafos/Pontos-de-Articulacao)

- [2 SAT](Codigos/Grafos/2-SAT)

- [LCA](Codigos/Grafos/LCA)

- [Pontes](Codigos/Grafos/Pontes)

	- [Componentes Aresta Biconexas](Codigos/Grafos/Pontes/Componentes-Aresta-Biconexas)

	- [Pontes](Codigos/Grafos/Pontes/Pontes)

- [Ciclos](Codigos/Grafos/Ciclos)

	- [Find Cycle](Codigos/Grafos/Ciclos/Find-Cycle)

	- [Find Negative Cycle](Codigos/Grafos/Ciclos/Find-Negative-Cycle)

- [Virtual Tree](Codigos/Grafos/Virtual-Tree)

- [HLD](Codigos/Grafos/HLD)

	- [HLD Vértice](Codigos/Grafos/HLD/HLD-Vértice)

	- [HLD Aresta](Codigos/Grafos/HLD/HLD-Aresta)

- [Matching](Codigos/Grafos/Matching)

	- [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

	- [Binary Lifting Query 2](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-2)

	- [Binary Lifting LCA](Codigos/Grafos/Binary-Lifting/Binary-Lifting-LCA)

	- [Binary Lifting Query](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query)

	- [Binary Lifting Query Aresta](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-Aresta)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

	- [BFS](Codigos/Grafos/Shortest-Paths/BFS)

	- [Bellman Ford](Codigos/Grafos/Shortest-Paths/Bellman-Ford)

	- [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

	- [01 BFS](Codigos/Grafos/Shortest-Paths/01-BFS)

	- [Floyd Warshall](Codigos/Grafos/Shortest-Paths/Floyd-Warshall)

	- [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)

- [Kruskal](Codigos/Grafos/Kruskal)

- [Fluxo](Codigos/Grafos/Fluxo)

- [Kosaraju](Codigos/Grafos/Kosaraju)

- [Caminho Euleriano](Codigos/Grafos/Caminho-Euleriano)

	- [Caminho Euleriano Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Direcionado)

	- [Caminho Euleriano Nao Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Nao-Direcionado)

### [Primitivas](Codigos/Primitivas)

- [Ponto 2D](Codigos/Primitivas/Ponto-2D)

- [Modular Int](Codigos/Primitivas/Modular-Int)

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

	- [Fenwick](Codigos/Estruturas-de-Dados/Fenwick-Tree/Fenwick)

	- [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree/Kd-Fenwick-Tree)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

	- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

	- [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

	- [Offline DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/Offline-DSU)

	- [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

	- [DSU Rollback Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback-Bipartido)

	- [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

	- [DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [XOR Trie](Codigos/Estruturas-de-Dados/XOR-Trie)

- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree)

	- [Merge Sort Tree Update](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree-Update)

	- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Implicit Treap](Codigos/Estruturas-de-Dados/Implicit-Treap)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

	- [Segment Tree Beats](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats)

	- [Segment Tree Iterativa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Iterativa)

	- [Segment Tree Lazy Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy-Esparsa)

	- [Segment Tree Kadane](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadane)

	- [Segment Tree Persisente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persisente)

	- [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

	- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

	- [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

	- [Segment Tree PA](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-PA)

	- [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

- [Operation Deque](Codigos/Estruturas-de-Dados/Operation-Deque)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [Treap](Codigos/Estruturas-de-Dados/Treap)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

### [Paradigmas](Codigos/Paradigmas)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

- [Mo](Codigos/Paradigmas/Mo)

	- [Mo Update](Codigos/Paradigmas/Mo/Mo-Update)

	- [Mo](Codigos/Paradigmas/Mo/Mo)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

### [Geometria](Codigos/Geometria)

- [Convex Hull](Codigos/Geometria/Convex-Hull)

### [String](Codigos/String)

- [Suffix Tree](Codigos/String/Suffix-Tree)

- [Prefix Function KMP](Codigos/String/Prefix-Function-KMP)

	- [KMP](Codigos/String/Prefix-Function-KMP/KMP)

	- [Automato KMP](Codigos/String/Prefix-Function-KMP/Automato-KMP)

- [Suffix Array](Codigos/String/Suffix-Array)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [Patricia Tree](Codigos/String/Patricia-Tree)

- [Suffix Automaton](Codigos/String/Suffix-Automaton)

- [EertreE](Codigos/String/EertreE)

- [Lyndon](Codigos/String/Lyndon)

- [Hashing](Codigos/String/Hashing)

	- [Hashing Dinâmico](Codigos/String/Hashing/Hashing-Dinâmico)

	- [Hashing](Codigos/String/Hashing/Hashing)

- [Trie](Codigos/String/Trie)

- [Z function](Codigos/String/Z-function)

- [Manacher](Codigos/String/Manacher)

### [Extra](Codigos/Extra)

- [CPP](Codigos/Extra/CPP)

- [Vim](Codigos/Extra/Vim)

- [Unordered Custom Hash](Codigos/Extra/Unordered-Custom-Hash)

- [Run](Codigos/Extra/Run)

- [Debug](Codigos/Extra/Debug)

- [Random](Codigos/Extra/Random)

- [Stress Test](Codigos/Extra/Stress-Test)




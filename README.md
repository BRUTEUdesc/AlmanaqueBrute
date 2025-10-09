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

- [XOR Gauss](Codigos/Matemática/XOR-Gauss)

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

	- [Gauss](Codigos/Matemática/Eliminação-Gaussiana/Gauss)

	- [Gauss Mod 2](Codigos/Matemática/Eliminação-Gaussiana/Gauss-Mod-2)

- [Convolução](Codigos/Matemática/Convolução)

	- [OR Convolution](Codigos/Matemática/Convolução/OR-Convolution)

	- [Subset Convolution](Codigos/Matemática/Convolução/Subset-Convolution)

	- [XOR Convolution](Codigos/Matemática/Convolução/XOR-Convolution)

	- [Dirichlet Convolution](Codigos/Matemática/Convolução/Dirichlet-Convolution)

		- [Dirichlet Inverse Prefix](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Inverse-Prefix)

		- [Dirichlet Convolution](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Convolution)

		- [Dirichlet Convolution Prefix](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Convolution-Prefix)

	- [AND Convolution](Codigos/Matemática/Convolução/AND-Convolution)

	- [LCM Convolution](Codigos/Matemática/Convolução/LCM-Convolution)

	- [GCD Convolution](Codigos/Matemática/Convolução/GCD-Convolution)

- [NTT](Codigos/Matemática/NTT)

	- [NTT](Codigos/Matemática/NTT/NTT)

	- [NTT Big Modulo](Codigos/Matemática/NTT/NTT-Big-Modulo)

	- [Taylor Shift](Codigos/Matemática/NTT/Taylor-Shift)

- [Continued Fractions](Codigos/Matemática/Continued-Fractions)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

- [Polinomios](Codigos/Matemática/Polinomios)

- [Discrete Root](Codigos/Matemática/Discrete-Root)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)

- [Floor Values](Codigos/Matemática/Floor-Values)

- [Floor and Mod Sum of Arithmetic Progressions](Codigos/Matemática/Floor-and-Mod-Sum-of-Arithmetic-Progressions)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [Fatoração e Primos](Codigos/Matemática/Fatoração-e-Primos)

	- [Pollard Rho](Codigos/Matemática/Fatoração-e-Primos/Pollard-Rho)

	- [Teste Primalidade](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade)

		- [Teste Primalidade Naive](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Teste-Primalidade-Naive)

		- [Miller Rabin](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Miller-Rabin)

	- [Fatores](Codigos/Matemática/Fatoração-e-Primos/Fatores)

		- [Fatoração Naive](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Naive)

		- [Fatoração Rápida](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Rápida)

	- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo)

		- [Crivo Linear](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo-Linear)

		- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo)

	- [Divisores](Codigos/Matemática/Fatoração-e-Primos/Divisores)

		- [Divisores Naive](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Naive)

		- [Divisores Rápido](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Rápido)

- [FFT](Codigos/Matemática/FFT)

### [Paradigmas](Codigos/Paradigmas)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

- [Mo](Codigos/Paradigmas/Mo)

	- [Mo Update](Codigos/Paradigmas/Mo/Mo-Update)

	- [Mo](Codigos/Paradigmas/Mo/Mo)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

### [Primitivas](Codigos/Primitivas)

- [Modular Int](Codigos/Primitivas/Modular-Int)

- [Ponto 2D](Codigos/Primitivas/Ponto-2D)

### [String](Codigos/String)

- [Suffix Tree](Codigos/String/Suffix-Tree)

- [Z function](Codigos/String/Z-function)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [EertreE](Codigos/String/EertreE)

- [Trie](Codigos/String/Trie)

- [Suffix Array](Codigos/String/Suffix-Array)

- [Prefix Function KMP](Codigos/String/Prefix-Function-KMP)

	- [Automato KMP](Codigos/String/Prefix-Function-KMP/Automato-KMP)

	- [KMP](Codigos/String/Prefix-Function-KMP/KMP)

- [Suffix Automaton](Codigos/String/Suffix-Automaton)

- [Hashing](Codigos/String/Hashing)

	- [Hashing](Codigos/String/Hashing/Hashing)

	- [Hashing Dinâmico](Codigos/String/Hashing/Hashing-Dinâmico)

- [Lyndon](Codigos/String/Lyndon)

- [Manacher](Codigos/String/Manacher)

- [Patricia Tree](Codigos/String/Patricia-Tree)

### [Geometria](Codigos/Geometria)

- [Convex Hull](Codigos/Geometria/Convex-Hull)

### [Grafos](Codigos/Grafos)

- [Caminho Euleriano](Codigos/Grafos/Caminho-Euleriano)

	- [Caminho Euleriano Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Direcionado)

	- [Caminho Euleriano Nao Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Nao-Direcionado)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

	- [Binary Lifting LCA](Codigos/Grafos/Binary-Lifting/Binary-Lifting-LCA)

	- [Binary Lifting Query 2](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-2)

	- [Binary Lifting Query](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query)

	- [Binary Lifting Query Aresta](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-Aresta)

- [Pontos de Articulacao](Codigos/Grafos/Pontos-de-Articulacao)

- [Centroids](Codigos/Grafos/Centroids)

	- [Centroid Decomposition](Codigos/Grafos/Centroids/Centroid-Decomposition)

	- [Centroid](Codigos/Grafos/Centroids/Centroid)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

	- [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

	- [01 BFS](Codigos/Grafos/Shortest-Paths/01-BFS)

	- [Bellman Ford](Codigos/Grafos/Shortest-Paths/Bellman-Ford)

	- [BFS](Codigos/Grafos/Shortest-Paths/BFS)

	- [Dial](Codigos/Grafos/Shortest-Paths/Dial)

	- [Floyd Warshall](Codigos/Grafos/Shortest-Paths/Floyd-Warshall)

	- [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

- [2 SAT](Codigos/Grafos/2-SAT)

- [Matching](Codigos/Grafos/Matching)

	- [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Centro e Diametro](Codigos/Grafos/Centro-e-Diametro)

- [Kosaraju](Codigos/Grafos/Kosaraju)

- [Virtual Tree](Codigos/Grafos/Virtual-Tree)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)

- [Block Cut Tree](Codigos/Grafos/Block-Cut-Tree)

- [Kruskal](Codigos/Grafos/Kruskal)

- [LCA](Codigos/Grafos/LCA)

- [Ciclos](Codigos/Grafos/Ciclos)

	- [Find Negative Cycle](Codigos/Grafos/Ciclos/Find-Negative-Cycle)

	- [Find Cycle](Codigos/Grafos/Ciclos/Find-Cycle)

- [HLD](Codigos/Grafos/HLD)

	- [HLD Vértice](Codigos/Grafos/HLD/HLD-Vértice)

	- [HLD Aresta](Codigos/Grafos/HLD/HLD-Aresta)

- [Fluxo](Codigos/Grafos/Fluxo)

- [Pontes](Codigos/Grafos/Pontes)

	- [Componentes Aresta Biconexas](Codigos/Grafos/Pontes/Componentes-Aresta-Biconexas)

	- [Pontes](Codigos/Grafos/Pontes/Pontes)

- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)

### [Extra](Codigos/Extra)

- [Unordered Custom Hash](Codigos/Extra/Unordered-Custom-Hash)

- [Debug](Codigos/Extra/Debug)

- [Run](Codigos/Extra/Run)

- [Vim](Codigos/Extra/Vim)

- [Stress Test](Codigos/Extra/Stress-Test)

- [Random](Codigos/Extra/Random)

- [CPP](Codigos/Extra/CPP)

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

	- [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree/Kd-Fenwick-Tree)

	- [Fenwick](Codigos/Estruturas-de-Dados/Fenwick-Tree/Fenwick)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [Implicit Treap](Codigos/Estruturas-de-Dados/Implicit-Treap)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

	- [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

	- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

- [Treap](Codigos/Estruturas-de-Dados/Treap)

- [XOR Trie](Codigos/Estruturas-de-Dados/XOR-Trie)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

	- [DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU)

	- [Offline DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/Offline-DSU)

	- [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

	- [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

	- [DSU Rollback Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback-Bipartido)

- [Operation Deque](Codigos/Estruturas-de-Dados/Operation-Deque)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

	- [Segment Tree PA](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-PA)

	- [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

	- [Segment Tree Iterativa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Iterativa)

	- [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

	- [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

	- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

	- [Segment Tree Persistente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persistente)

	- [Segment Tree Lazy Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy-Esparsa)

	- [Segment Tree Kadane](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadane)

	- [Segment Tree Beats](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree)

	- [Merge Sort Tree Update](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree-Update)

	- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree)




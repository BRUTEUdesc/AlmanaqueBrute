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

### [Paradigmas](Codigos/Paradigmas)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [Mo](Codigos/Paradigmas/Mo)

	- [Mo Update](Codigos/Paradigmas/Mo/Mo-Update)

	- [Mo](Codigos/Paradigmas/Mo/Mo)

### [Extra](Codigos/Extra)

- [Debug](Codigos/Extra/Debug)

- [Vim](Codigos/Extra/Vim)

- [Stress Test](Codigos/Extra/Stress-Test)

- [Run](Codigos/Extra/Run)

- [Random](Codigos/Extra/Random)

- [CPP](Codigos/Extra/CPP)

- [Unordered Custom Hash](Codigos/Extra/Unordered-Custom-Hash)

### [Grafos](Codigos/Grafos)

- [Block Cut Tree](Codigos/Grafos/Block-Cut-Tree)

- [LCA](Codigos/Grafos/LCA)

- [2 SAT](Codigos/Grafos/2-SAT)

- [Centroids](Codigos/Grafos/Centroids)

	- [Centroid Decomposition](Codigos/Grafos/Centroids/Centroid-Decomposition)

	- [Centroid](Codigos/Grafos/Centroids/Centroid)

- [Virtual Tree](Codigos/Grafos/Virtual-Tree)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)

- [Kosaraju](Codigos/Grafos/Kosaraju)

- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)

- [Caminho Euleriano](Codigos/Grafos/Caminho-Euleriano)

	- [Caminho Euleriano Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Direcionado)

	- [Caminho Euleriano Nao Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Nao-Direcionado)

- [Fluxo](Codigos/Grafos/Fluxo)

- [Matching](Codigos/Grafos/Matching)

	- [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Centro e Diametro](Codigos/Grafos/Centro-e-Diametro)

- [HLD](Codigos/Grafos/HLD)

	- [HLD Aresta](Codigos/Grafos/HLD/HLD-Aresta)

	- [HLD Vértice](Codigos/Grafos/HLD/HLD-Vértice)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

	- [BFS](Codigos/Grafos/Shortest-Paths/BFS)

	- [01 BFS](Codigos/Grafos/Shortest-Paths/01-BFS)

	- [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

	- [Bellman Ford](Codigos/Grafos/Shortest-Paths/Bellman-Ford)

	- [Floyd Warshall](Codigos/Grafos/Shortest-Paths/Floyd-Warshall)

	- [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

	- [Dial](Codigos/Grafos/Shortest-Paths/Dial)

- [Kruskal](Codigos/Grafos/Kruskal)

- [Ciclos](Codigos/Grafos/Ciclos)

	- [Find Cycle](Codigos/Grafos/Ciclos/Find-Cycle)

	- [Find Negative Cycle](Codigos/Grafos/Ciclos/Find-Negative-Cycle)

- [Pontes](Codigos/Grafos/Pontes)

	- [Componentes Aresta Biconexas](Codigos/Grafos/Pontes/Componentes-Aresta-Biconexas)

	- [Pontes](Codigos/Grafos/Pontes/Pontes)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

	- [Binary Lifting LCA](Codigos/Grafos/Binary-Lifting/Binary-Lifting-LCA)

	- [Binary Lifting Query Aresta](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-Aresta)

	- [Binary Lifting Query](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query)

	- [Binary Lifting Query 2](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-2)

- [Pontos de Articulacao](Codigos/Grafos/Pontos-de-Articulacao)

### [Primitivas](Codigos/Primitivas)

- [Modular Int](Codigos/Primitivas/Modular-Int)

- [Ponto 2D](Codigos/Primitivas/Ponto-2D)

### [String](Codigos/String)

- [Hashing](Codigos/String/Hashing)

	- [Hashing](Codigos/String/Hashing/Hashing)

	- [Hashing Dinâmico](Codigos/String/Hashing/Hashing-Dinâmico)

- [Prefix Function KMP](Codigos/String/Prefix-Function-KMP)

	- [KMP](Codigos/String/Prefix-Function-KMP/KMP)

	- [Automato KMP](Codigos/String/Prefix-Function-KMP/Automato-KMP)

- [Trie](Codigos/String/Trie)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [Suffix Tree](Codigos/String/Suffix-Tree)

- [EertreE](Codigos/String/EertreE)

- [Lyndon](Codigos/String/Lyndon)

- [Suffix Automaton](Codigos/String/Suffix-Automaton)

- [Suffix Array](Codigos/String/Suffix-Array)

- [Patricia Tree](Codigos/String/Patricia-Tree)

- [Manacher](Codigos/String/Manacher)

- [Z function](Codigos/String/Z-function)

### [Geometria](Codigos/Geometria)

- [Convex Hull](Codigos/Geometria/Convex-Hull)

### [Matemática](Codigos/Matemática)

- [Fatoração e Primos](Codigos/Matemática/Fatoração-e-Primos)

	- [Teste Primalidade](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade)

		- [Miller Rabin](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Miller-Rabin)

		- [Teste Primalidade Naive](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Teste-Primalidade-Naive)

	- [Pollard Rho](Codigos/Matemática/Fatoração-e-Primos/Pollard-Rho)

	- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo)

		- [Crivo Linear](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo-Linear)

		- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo)

	- [Fatores](Codigos/Matemática/Fatoração-e-Primos/Fatores)

		- [Fatoração Rápida](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Rápida)

		- [Fatoração Naive](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Naive)

	- [Divisores](Codigos/Matemática/Fatoração-e-Primos/Divisores)

		- [Divisores Rápido](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Rápido)

		- [Divisores Naive](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Naive)

- [GCD](Codigos/Matemática/GCD)

- [FFT](Codigos/Matemática/FFT)

- [Discrete Root](Codigos/Matemática/Discrete-Root)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

- [Polinomios](Codigos/Matemática/Polinomios)

- [Convolução](Codigos/Matemática/Convolução)

	- [XOR Convolution](Codigos/Matemática/Convolução/XOR-Convolution)

	- [LCM Convolution](Codigos/Matemática/Convolução/LCM-Convolution)

	- [Dirichlet Convolution](Codigos/Matemática/Convolução/Dirichlet-Convolution)

		- [Dirichlet Convolution Prefix](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Convolution-Prefix)

		- [Dirichlet Convolution](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Convolution)

		- [Dirichlet Inverse Prefix](Codigos/Matemática/Convolução/Dirichlet-Convolution/Dirichlet-Inverse-Prefix)

	- [GCD Convolution](Codigos/Matemática/Convolução/GCD-Convolution)

	- [Subset Convolution](Codigos/Matemática/Convolução/Subset-Convolution)

	- [AND Convolution](Codigos/Matemática/Convolução/AND-Convolution)

	- [OR Convolution](Codigos/Matemática/Convolução/OR-Convolution)

- [Floor Values](Codigos/Matemática/Floor-Values)

- [Floor and Mod Sum of Arithmetic Progressions](Codigos/Matemática/Floor-and-Mod-Sum-of-Arithmetic-Progressions)

- [XOR Gauss](Codigos/Matemática/XOR-Gauss)

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

	- [Gauss Mod 2](Codigos/Matemática/Eliminação-Gaussiana/Gauss-Mod-2)

	- [Gauss](Codigos/Matemática/Eliminação-Gaussiana/Gauss)

- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)

- [NTT](Codigos/Matemática/NTT)

	- [NTT Big Modulo](Codigos/Matemática/NTT/NTT-Big-Modulo)

	- [Taylor Shift](Codigos/Matemática/NTT/Taylor-Shift)

	- [NTT](Codigos/Matemática/NTT/NTT)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Operation Deque](Codigos/Estruturas-de-Dados/Operation-Deque)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

	- [DSU Rollback Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback-Bipartido)

	- [Offline DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/Offline-DSU)

	- [DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU)

	- [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

	- [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

- [Implicit Treap](Codigos/Estruturas-de-Dados/Implicit-Treap)

- [XOR Trie](Codigos/Estruturas-de-Dados/XOR-Trie)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

	- [Segment Tree Kadane](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadane)

	- [Segment Tree Lazy Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy-Esparsa)

	- [Segment Tree Persisente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persisente)

	- [Segment Tree Iterativa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Iterativa)

	- [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

	- [Segment Tree Beats](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats)

	- [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

	- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

	- [Segment Tree PA](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-PA)

	- [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree)

	- [Merge Sort Tree Update](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree-Update)

	- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

	- [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

	- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

- [Treap](Codigos/Estruturas-de-Dados/Treap)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

	- [Fenwick](Codigos/Estruturas-de-Dados/Fenwick-Tree/Fenwick)

	- [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree/Kd-Fenwick-Tree)




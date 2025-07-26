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

### [Primitivas](Codigos/Primitivas)

- [Modular Int](Codigos/Primitivas/Modular-Int)

- [Ponto 2D](Codigos/Primitivas/Ponto-2D)

### [Matemática](Codigos/Matemática)

- [Teorema do Resto Chinês](Codigos/Matemática/Teorema-do-Resto-Chinês)

- [FFT](Codigos/Matemática/FFT)

- [Exponenciação Modular Rápida](Codigos/Matemática/Exponenciação-Modular-Rápida)

- [XOR Gauss](Codigos/Matemática/XOR-Gauss)

- [NTT](Codigos/Matemática/NTT)

	- [NTT](Codigos/Matemática/NTT/NTT)

	- [NTT Big Modulo](Codigos/Matemática/NTT/NTT-Big-Modulo)

	- [Taylor Shift](Codigos/Matemática/NTT/Taylor-Shift)

- [Fatoração e Primos](Codigos/Matemática/Fatoração-e-Primos)

	- [Teste Primalidade](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade)

		- [Teste Primalidade Naive](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Teste-Primalidade-Naive)

		- [Miller Rabin](Codigos/Matemática/Fatoração-e-Primos/Teste-Primalidade/Miller-Rabin)

	- [Pollard Rho](Codigos/Matemática/Fatoração-e-Primos/Pollard-Rho)

	- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo)

		- [Crivo](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo)

		- [Crivo Linear](Codigos/Matemática/Fatoração-e-Primos/Crivo/Crivo-Linear)

	- [Fatores](Codigos/Matemática/Fatoração-e-Primos/Fatores)

		- [Fatoração Rápida](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Rápida)

		- [Fatoração Naive](Codigos/Matemática/Fatoração-e-Primos/Fatores/Fatoração-Naive)

	- [Divisores](Codigos/Matemática/Fatoração-e-Primos/Divisores)

		- [Divisores Rápido](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Rápido)

		- [Divisores Naive](Codigos/Matemática/Fatoração-e-Primos/Divisores/Divisores-Naive)

- [Inverso Modular](Codigos/Matemática/Inverso-Modular)

- [Convolução](Codigos/Matemática/Convolução)

	- [XOR Convolution](Codigos/Matemática/Convolução/XOR-Convolution)

	- [Subset Convolution](Codigos/Matemática/Convolução/Subset-Convolution)

	- [GCD Convolution](Codigos/Matemática/Convolução/GCD-Convolution)

	- [OR Convolution](Codigos/Matemática/Convolução/OR-Convolution)

	- [LCM Convolution](Codigos/Matemática/Convolução/LCM-Convolution)

	- [AND Convolution](Codigos/Matemática/Convolução/AND-Convolution)

- [Floor Values](Codigos/Matemática/Floor-Values)

- [Totiente de Euler](Codigos/Matemática/Totiente-de-Euler)

- [Eliminação Gaussiana](Codigos/Matemática/Eliminação-Gaussiana)

	- [Gauss](Codigos/Matemática/Eliminação-Gaussiana/Gauss)

	- [Gauss Mod 2](Codigos/Matemática/Eliminação-Gaussiana/Gauss-Mod-2)

- [GCD](Codigos/Matemática/GCD)

### [String](Codigos/String)

- [Trie](Codigos/String/Trie)

- [Z function](Codigos/String/Z-function)

- [Manacher](Codigos/String/Manacher)

- [EertreE](Codigos/String/EertreE)

- [Hashing](Codigos/String/Hashing)

	- [Hashing Dinâmico](Codigos/String/Hashing/Hashing-Dinâmico)

	- [Hashing](Codigos/String/Hashing/Hashing)

- [Aho Corasick](Codigos/String/Aho-Corasick)

- [Patricia Tree](Codigos/String/Patricia-Tree)

- [Lyndon](Codigos/String/Lyndon)

- [Suffix Automaton](Codigos/String/Suffix-Automaton)

- [Suffix Array](Codigos/String/Suffix-Array)

- [Prefix Function KMP](Codigos/String/Prefix-Function-KMP)

	- [Automato KMP](Codigos/String/Prefix-Function-KMP/Automato-KMP)

	- [KMP](Codigos/String/Prefix-Function-KMP/KMP)

- [Suffix Tree](Codigos/String/Suffix-Tree)

### [Estruturas de Dados](Codigos/Estruturas-de-Dados)

- [Treap](Codigos/Estruturas-de-Dados/Treap)

- [Interval Tree](Codigos/Estruturas-de-Dados/Interval-Tree)

- [Operation Deque](Codigos/Estruturas-de-Dados/Operation-Deque)

- [LiChao Tree](Codigos/Estruturas-de-Dados/LiChao-Tree)

- [Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree)

	- [Fenwick](Codigos/Estruturas-de-Dados/Fenwick-Tree/Fenwick)

	- [Kd Fenwick Tree](Codigos/Estruturas-de-Dados/Fenwick-Tree/Kd-Fenwick-Tree)

- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree)

	- [Merge Sort Tree](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree)

	- [Merge Sort Tree Update](Codigos/Estruturas-de-Dados/Merge-Sort-Tree/Merge-Sort-Tree-Update)

- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree)

	- [Segment Tree PA](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-PA)

	- [Segment Tree Iterativa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Iterativa)

	- [Segment Tree Kadane](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Kadane)

	- [Segment Tree Persisente](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Persisente)

	- [Segment Tree](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree)

	- [Segment Tree Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Esparsa)

	- [Segment Tree Lazy](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy)

	- [Segment Tree Beats](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Beats)

	- [Segment Tree 2D](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-2D)

	- [Segment Tree Lazy Esparsa](Codigos/Estruturas-de-Dados/Segment-Tree/Segment-Tree-Lazy-Esparsa)

- [Operation Stack](Codigos/Estruturas-de-Dados/Operation-Stack)

- [Implicit Treap](Codigos/Estruturas-de-Dados/Implicit-Treap)

- [Operation Queue](Codigos/Estruturas-de-Dados/Operation-Queue)

- [Disjoint Set Union](Codigos/Estruturas-de-Dados/Disjoint-Set-Union)

	- [DSU Rollback Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback-Bipartido)

	- [DSU Rollback](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Rollback)

	- [DSU Bipartido](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU-Bipartido)

	- [Offline DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/Offline-DSU)

	- [DSU](Codigos/Estruturas-de-Dados/Disjoint-Set-Union/DSU)

- [Ordered Set](Codigos/Estruturas-de-Dados/Ordered-Set)

- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table)

	- [Disjoint Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Disjoint-Sparse-Table)

	- [Sparse Table](Codigos/Estruturas-de-Dados/Sparse-Table/Sparse-Table)

- [XOR Trie](Codigos/Estruturas-de-Dados/XOR-Trie)

### [Paradigmas](Codigos/Paradigmas)

- [Exponenciação de Matriz](Codigos/Paradigmas/Exponenciação-de-Matriz)

- [All Submasks](Codigos/Paradigmas/All-Submasks)

- [DP de Permutacao](Codigos/Paradigmas/DP-de-Permutacao)

- [Divide and Conquer](Codigos/Paradigmas/Divide-and-Conquer)

- [Convex Hull Trick](Codigos/Paradigmas/Convex-Hull-Trick)

- [Mo](Codigos/Paradigmas/Mo)

	- [Mo](Codigos/Paradigmas/Mo/Mo)

	- [Mo Update](Codigos/Paradigmas/Mo/Mo-Update)

- [Busca Binaria Paralela](Codigos/Paradigmas/Busca-Binaria-Paralela)

- [Busca Ternaria](Codigos/Paradigmas/Busca-Ternaria)

### [Geometria](Codigos/Geometria)

- [Convex Hull](Codigos/Geometria/Convex-Hull)

### [Extra](Codigos/Extra)

- [Stress Test](Codigos/Extra/Stress-Test)

- [Unordered Custom Hash](Codigos/Extra/Unordered-Custom-Hash)

- [CPP](Codigos/Extra/CPP)

- [Vim](Codigos/Extra/Vim)

- [Run](Codigos/Extra/Run)

- [Debug](Codigos/Extra/Debug)

- [Random](Codigos/Extra/Random)

### [Grafos](Codigos/Grafos)

- [Fluxo](Codigos/Grafos/Fluxo)

- [Kosaraju](Codigos/Grafos/Kosaraju)

- [Shortest Paths](Codigos/Grafos/Shortest-Paths)

	- [Floyd Warshall](Codigos/Grafos/Shortest-Paths/Floyd-Warshall)

	- [SPFA](Codigos/Grafos/Shortest-Paths/SPFA)

	- [Bellman Ford](Codigos/Grafos/Shortest-Paths/Bellman-Ford)

	- [Dijkstra](Codigos/Grafos/Shortest-Paths/Dijkstra)

	- [BFS](Codigos/Grafos/Shortest-Paths/BFS)

	- [01 BFS](Codigos/Grafos/Shortest-Paths/01-BFS)

- [Block Cut Tree](Codigos/Grafos/Block-Cut-Tree)

- [Kruskal](Codigos/Grafos/Kruskal)

- [Pontos de Articulacao](Codigos/Grafos/Pontos-de-Articulacao)

- [Centro e Diametro](Codigos/Grafos/Centro-e-Diametro)

- [Virtual Tree](Codigos/Grafos/Virtual-Tree)

- [Centroids](Codigos/Grafos/Centroids)

	- [Centroid Decomposition](Codigos/Grafos/Centroids/Centroid-Decomposition)

	- [Centroid](Codigos/Grafos/Centroids/Centroid)

- [Caminho Euleriano](Codigos/Grafos/Caminho-Euleriano)

	- [Caminho Euleriano Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Direcionado)

	- [Caminho Euleriano Nao Direcionado](Codigos/Grafos/Caminho-Euleriano/Caminho-Euleriano-Nao-Direcionado)

- [Stoer–Wagner Min Cut](Codigos/Grafos/Stoer–Wagner-Min-Cut)

- [2 SAT](Codigos/Grafos/2-SAT)

- [Matching](Codigos/Grafos/Matching)

	- [Hungaro](Codigos/Grafos/Matching/Hungaro)

- [Binary Lifting](Codigos/Grafos/Binary-Lifting)

	- [Binary Lifting Query 2](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-2)

	- [Binary Lifting Query Aresta](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query-Aresta)

	- [Binary Lifting Query](Codigos/Grafos/Binary-Lifting/Binary-Lifting-Query)

	- [Binary Lifting LCA](Codigos/Grafos/Binary-Lifting/Binary-Lifting-LCA)

- [Pontes](Codigos/Grafos/Pontes)

	- [Pontes](Codigos/Grafos/Pontes/Pontes)

	- [Componentes Aresta Biconexas](Codigos/Grafos/Pontes/Componentes-Aresta-Biconexas)

- [Ciclos](Codigos/Grafos/Ciclos)

	- [Find Negative Cycle](Codigos/Grafos/Ciclos/Find-Negative-Cycle)

	- [Find Cycle](Codigos/Grafos/Ciclos/Find-Cycle)

- [LCA](Codigos/Grafos/LCA)

- [HLD](Codigos/Grafos/HLD)

	- [HLD Vértice](Codigos/Grafos/HLD/HLD-Vértice)

	- [HLD Aresta](Codigos/Grafos/HLD/HLD-Aresta)

- [Inverse Graph](Codigos/Grafos/Inverse-Graph)




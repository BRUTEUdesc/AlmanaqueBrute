# [Kosaraju](kosaraju.cpp)

Algoritmo que encontra as componentes fortemente conexas (SCCs) de um grafo direcionado.
O algoritmo de Kosaraju resolve isso em $\mathcal{O}(N + M)$, onde $N$ é o número de vértices e $M$ é o número de arestas do grafo.

O componente fortemente conexo de cada vértice é armazenado no vetor `root`.
A grafo condensado é armazenado no vetor `gc`.

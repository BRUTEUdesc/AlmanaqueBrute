# [01 BFS](bfs01.cpp)

Computa o menor caminho entre nodos de um grafo com arestas de peso 0 ou 1.

Dado um nodo $s$, computa o menor caminho de $s$ para todos os outros nodos em $\mathcal{O}(V + E)$.

Muito semelhante a uma BFS, mas usa uma `deque` (fila dupla) ao invés de uma fila comum.

**Importante**: As arestas só podem ter peso 0 ou 1.
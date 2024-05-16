# 0-1 BFS

Computa o menor caminho entre nós de um grafo com arestas de peso 0 ou 1.

Dado um nó $s$, computa o menor caminho de $s$ para todos os outros nós em $\mathcal{O}(V + E)$.

Muito semelhante a uma BFS, mas usa uma `deque` (fila dupla) ao invés de uma fila comum.

**Importante**: As arestas só podem ter peso 0 ou 1.
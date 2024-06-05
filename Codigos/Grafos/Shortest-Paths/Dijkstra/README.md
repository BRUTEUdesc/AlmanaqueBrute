# [Dijkstra](dijkstra.cpp)

Computa o menor caminho entre nodos de um grafo com pesos quaisquer nas arestas.

Dado um nodo $s$, computa o menor caminho de $s$ para todos os outros nodos em $\mathcal{O}((V + E) \cdot \log E)$.

Muito semelhante a uma BFS, mas usa uma fila de prioridade ao invés de uma fila comum.

**Importante**: O grafo não pode conter arestas de peso negativo.
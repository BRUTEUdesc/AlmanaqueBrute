# [Dijkstra](dijkstra.cpp)

Computa o menor caminho entre nós de um grafo com pesos quaisquer nas arestas.

Dado um nó $s$, computa o menor caminho de $s$ para todos os outros nós em $\mathcal{O}((V + E) * log(E))$.

Muito semelhante a uma BFS, mas usa uma fila de prioridade ao invés de uma fila comum.

**Importante**: O grafo não pode conter ciclos de peso negativo.
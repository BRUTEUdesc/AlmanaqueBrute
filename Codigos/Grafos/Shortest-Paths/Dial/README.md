# [Dial](dial.cpp)

Computa o menor caminho entre nodos de um grafo com pesos nas arestas.

Útil quando o maior peso de uma aresta $D$ não é muito grande (inutilizável para $D \leq 10^9$, vide a
complexidade abaixo).

Dado um nodo $s$, computa o menor caminho de $s$ para todos os outros nodos em $\mathcal{O}(D \cdot V + E)$.

Muito semelhante a uma BFS, mas simula $D+1$ filas, uma para cada distância a cada passo do algoritmo, ao invés de uma só fila.

**Importante**: O grafo não pode conter arestas de peso negativo.

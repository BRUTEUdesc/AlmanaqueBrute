# [Caminho Euleriano (Grafo Nao Direcionado)](undirected_eulerian_path.cpp)

Algoritmo para encontrar um caminho euleriano em um grafo não direcionado em $\mathcal{O}(V + E)$. O algoritmo também encontrará um ciclo euleriano se o mesmo existir. Se nem um ciclo nem um caminho euleriano existir, o algoritmo retornará um vetor vazio.

**Definição**: Um caminho euleriano é um caminho que passa por todas as arestas de um grafo exatamente uma vez. Um ciclo euleriano é um caminho euleriano que começa e termina no mesmo vértice. A condição de existência de um ciclo euleriano (em um grafo não direcionado) é que todos os vértices do grafo possuam grau par. A condição de existência de um caminho euleriano (em um grafo não direcionado) é que o grafo possua no exatamente dois vértices com grau ímpar, um deles será o vértice de início e o outro o vértice de término.

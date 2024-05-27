# [Pontes](find_bridges.cpp)

Algoritmo que acha pontes em um grafo utilizando DFS. $\mathcal{O}(V + E)$. Pontes são aresta cuja remoção aumenta o número de componentes conexas do grafo.

Nesse código também há uma função que acha componentes aresta-biconexas, que são componentes que para se desconectar é necessário remover pelo menos duas arestas. Para obter essas componentes, basta achar as pontes e contrair o resto do grafo, o resultado é uma árvore.
# [Componentes Aresta Biconexas](ebcc_components.cpp)

Código que acha componentes aresta-biconexas, que são componentes que para se desconectar é necessário remover pelo menos duas arestas. Para obter essas componentes, basta achar as pontes e contrair o resto do grafo, o resultado é uma árvore em que as arestas são as pontes do grafo original.

Esse algoritmo acha as pontes e constrói o grafo comprimido em $\mathcal{O}(V + E)$. Pontes são arestas cuja remoção aumenta o número de componentes conexas do grafo.

No código, `ebcc[u]` é o índice da componente aresta-biconexa a qual o vértice `u` pertence.
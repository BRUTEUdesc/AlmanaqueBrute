# [Centroid Decomposition](centroid_decomposition.cpp)

Algoritmo que constrói a decomposição por centroides de uma árvore em $\mathcal{O}(N \log N)$.

Basicamente, a decomposição consiste em, repetidamente:

- Encontrar o centroide da árvore atual.
- Remover o centroide e decompor as subárvores restantes.

A decomposição vai gerar uma nova árvore (chamada comumente de "Centroid Tree") onde cada nodo é um centroide da árvore original e as arestas representam a relação de pai-filho entre os centroides. A árvore tem altura $\log N$.

No código, `dis[u][j]` é a distância entre o nodo $u$ e seu $j$-ésimo ancestral na Centroid Tree.

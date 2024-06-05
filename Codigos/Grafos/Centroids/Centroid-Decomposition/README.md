# [Centroid Decomposition](centroid_decomposition.cpp)

Algoritmo que constrói a decomposição por centróides de uma árvore em $\mathcal{O}(N \log N)$.

Basicamente, a decomposição consiste em, repetidamente:

- Encontrar o centróide da árvore atual.
- Remover o centróide e decompor as subárvores restantes.

A decomposição vai gerar uma nova árvore (chamada comumente de "Centroid Tree") onde cada nodo é um centróide da árvore original e as arestas representam a relação de pai-filho entre os centróides. A árvore tem altura $\log N$.

No código, `dis[u][j]` é a distância entre o nodo $u$ e seu $j$-ésimo ancestral na Centroid Tree.

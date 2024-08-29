# [Block Cut Tree](block_cut_tree.cpp)

Algoritmo que separa o grafo em componentes biconexas em $\mathcal{O}(V + E)$.

- `id[u]` é o index do nodo `u` na block cut tree
- `is_articulation_point(u)` diz se o nodo `u` é ou não é um ponto de articulação.
- `number_of_splits(u)` diz a quantidade de componentes conexas que o grafo
    terá se o nodo `u` for removido.

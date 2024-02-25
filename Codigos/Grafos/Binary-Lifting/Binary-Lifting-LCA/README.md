# [Binary Lifting](binary_lifting_lca.cpp)

Usa uma matriz para precomputar os ancestrais de um nodo, em que `up[u][i]` é o $2 ^ i$-ésimo ancestral de `u`. A construção é $\mathcal{O}(n \log n)$, e é possível consultar pelo $k$-ésimo ancestral de um nodo e pelo **LCA** de dois nodos em $\mathcal{O}(\log n)$.

**LCA**: Lowest Common Ancestor, o LCA de dois nodos $u$ e $v$ é o nodo mais profundo que é ancestral de ambos.

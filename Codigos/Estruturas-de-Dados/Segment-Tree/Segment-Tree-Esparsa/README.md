# [Segment Tree Esparsa](seg_tree_sparse.cpp)

Segment Tree Esparsa, ou seja, não armazena todos os nós da árvore, apenas os necessários, dessa forma ela suporta operações em intervalos arbitrários. A construção é $\mathcal{O}(1)$ e as operações de consulta e update são $\mathcal{O}(log(L))$, onde $L$ é o tamanho do intervalo. A implementação suporta operações de consulta em intervalo e update pontual. Está implementada para soma, mas pode ser facilmente modificada para outras operações.

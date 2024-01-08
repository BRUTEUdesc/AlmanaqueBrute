# [Sparse Seg Tree](seg_tree_sparse.cpp)

Seg Tree Esparsa, ou seja, uma seg tree que não guarda todos os nós, mas apenas os nós que são necessários para responder as queries, permitindo fazer queries em intervalos de tamanho arbitrário.

Seja $LEN$ o tamanho do intervalo em que a Seg Tree foi construída:

- Complexidade de tempo (Pré-processamento): $O(1)$
- Complexidade de tempo (Consulta em intervalo): $O(log(LEN))$
- Complexidade de tempo (Update em ponto): $O(log(LEN))$
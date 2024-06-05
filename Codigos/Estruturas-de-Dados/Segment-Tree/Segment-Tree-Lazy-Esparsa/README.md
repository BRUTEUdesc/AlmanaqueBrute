# [Segment Tree Lazy Esparsa](seg_tree_sparse_lazy.cpp)

Segment Tree com Lazy Propagation e Esparsa. Está implementada com update de soma em range e atribuição em range, e query de soma em range. Construção em $\mathcal{O}(1)$ e operações de update e query em $\mathcal{O}(\log L)$, onde $L$ é o tamanho do intervalo.

**Dica**: No construtor da Seg Tree, fazer `t.reserve(MAX); lazy.reserve(MAX); replace.reserve(MAX); Lc.reserve(MAX); Rc.reserve(MAX);` pode ajudar bastante no runtime, pois aloca espaço para os vetores e evita muitas realocações durante a execução. Nesse caso, `MAX` é geralmente $\mathcal{O}(Q \cdot \log L)$, onde $Q$ é o número de queries e $L$ é o tamanho do intervalo.
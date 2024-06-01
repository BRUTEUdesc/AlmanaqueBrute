# [Seg Tree Persistente](seg_tree_persistent.cpp)

Uma Seg Tree Esparsa, só que com persistência, ou seja, pode voltar para qualquer estado anterior da árvore, antes de qualquer modificação.

Os métodos `query` e `update` agora recebem um parâmetro a mais, que é o índice da root (versão da árvore) que se deja modificar.

O vetor `roots` guarda na posição `i` a root da árvore após o `i`-ésimo update.

**Dica**: No construtor da Seg Tree, fazer `t.reserve(MAX); Lc.reserve(MAX); Rc.reserve(MAX); roots.reserve(Q);` pode ajudar bastante no runtime, pois aloca espaço para os vetores e evita muitas realocações durante a execução. Nesse caso, `MAX` é geralmente $\mathcal{O}(Q \cdot log(L))$, onde $Q$ é o número de queries e $L$ é o tamanho do intervalo.
# [Seg Tree Persistente](seg_tree_persistent.cpp)

Uma Seg Tree Esparsa, só que com persistência, ou seja, pode voltar para qualquer estado anterior da árvore, antes de qualquer modificação.

Os métodos `query` e `update` agora recebem um parâmetro a mais, que é o índice da root (versão da árvore) que se deja modificar.

O vetor `roots` guarda na posição `i` a root da árvore após o `i`-ésimo update.
# [Treap](treap.cpp)

Uma árvore de busca binaria balanceada. Se não quiser ter elementos repeditos, basta fazer `treap::setify = true`.

- insert($X$) insere um elemento x na arvore
- remove($X$) remove uma ocorrência de $X$ na árvore, e retorna falso caso não tenha nenhuma ocorrência de $X$ na árvore.
- size($T$) retorna o tamanho da sub-árvore $T$.
- find($X$) retorna true se $X$ aparece pelo menos uma vez na árvore.

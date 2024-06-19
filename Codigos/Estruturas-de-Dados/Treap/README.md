# [Treap](treap.cpp)

Uma árvore de busca binária balanceada. Se não quiser ter elementos repetidos, basta fazer `treap::setify = true`.

- `insert(X)`: insere um elemento $X$ na árvore em $\mathcal{O}(\log N)$
- `remove(X)`: remove uma ocorrência de $X$ na árvore, e retorna `false` caso não tenha nenhuma ocorrência de $X$ na árvore em $\mathcal{O}(\log N)$.
- `find(X)`: retorna `true` se $X$ aparece pelo menos uma vez na árvore em $\mathcal{O}(\log N)$.

# [Implicit Treap](implicit_treap.cpp)

Simula um array com as seguintes operações em $\mathcal{O}(log(N))$:

* Inserir um elemento $X$ na posição $i$ (todos os elementos em posições maiores que $i$ serão empurrados para a direita).
* Remover o elemento na posição $i$ (todos os elementos em posições maiores que $i$ serão puxados para a esquerda).
* Query em intervalo `[L, R]` de soma, maximo, minimo, gcd, etc...
* Adição em intervalo `[L, R]` (sua operação deve suportar propagação lazy)
* Reverter um intervalo `[L, R]`, ou seja, `a[L], a[L + 1], ..., a[R]` -> `a[R], a[R - 1], ..., a[L]`.

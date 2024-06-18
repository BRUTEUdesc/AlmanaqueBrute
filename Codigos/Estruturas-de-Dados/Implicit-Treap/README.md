# [Implicit Treap](implicit_treap.cpp)

Simula um array com as seguintes operações em $\mathcal{O}(log(N))$:

- Inserir um elemento $X$ na posição $i$ (todos os elementos em posições maiores que $i$ serão "empurrados" para a direita).
- Remover o elemento na posição $i$ (todos os elementos em posições maiores que $i$ serão "puxados" para a esquerda).
- Query em intervalo $[L, R]$ de alguma operação. Pode ser soma, máximo, mínimo, `gcd`, etc.
- Adição em intervalo $[L, R]$ (sua operação deve suportar propagação lazy).
- Reverter um intervalo $[L, R]$, ou seja, $a[L], a[L + 1], \cdots, a[R] \rightarrow a[R], a[R - 1], \cdots, a[L]$.

**Obs**: Inserir em uma posição $<0$ vai inserir na posição $0$, assim como inserir em uma posição $>\text{Tamanho da Treap}$ vai inserir no final dela.

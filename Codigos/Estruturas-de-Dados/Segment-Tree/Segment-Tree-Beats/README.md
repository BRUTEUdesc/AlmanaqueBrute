# [Segment Tree Beats](seg_tree_beats.cpp)

Segment Tree que suporta update de máximo em range, update de mínimo em range, update de soma em range, e query de soma em range. A construção é $\mathcal{O}(n)$ e as operações de consulta e update são $\mathcal{O}(\log^2 n)$.

Update de máximo em um range $[L, R]$ passando um valor $X$, significa para cada $i$ tal que $L \le i \le R$, fazer a operação $a[i] = max(a[i], X)$. Update de mínimo é análogo.

**Obs**: Se não usar o update de soma, a complexidade é das operações é $\mathcal{O}(\log n)$

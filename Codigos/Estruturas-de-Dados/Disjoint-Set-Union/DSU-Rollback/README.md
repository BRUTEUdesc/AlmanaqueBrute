# [DSU com Rollback](rollback_dsu.cpp)

DSU que desfaz as últimas operações. O método $checkpoint$ salva o estado atual da estrutura, e o método $rollback$ desfaz as últimas operações até o último checkpoint. As operações de unir dois conjuntos e verificar em qual conjunto um elemento está são $\mathcal{O}(\log n)$, o rollback é $\mathcal{O}(k)$, onde $k$ é o número de alterações a serem desfeitas e o $checkpoint$ é $\mathcal{O}(1)$. Importante notar que o rollback não altera a complexidade de uma solução, uma vez que $\sum k = \mathcal{O}(q)$, onde $q$ é o número de operações realizadas.

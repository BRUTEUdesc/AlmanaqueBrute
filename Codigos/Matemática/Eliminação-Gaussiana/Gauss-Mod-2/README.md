# [Eliminação Gaussiana (MOD 2)](gauss_mod2.cpp)

Método de eliminação gaussiana para resolução de sistemas lineares com coeficientes em $\mathbb{Z}_2$ (inteiros módulo 2), a complexidade é $\mathcal{O}(n^3 / \mathcal{w})$, onde $\mathcal{w}$ é a palavra do processador (geralmente 32 ou 64 bits, dependendo da arquitetura).

No código, a constante $M$ deve ser definida como o `(número de variáveis + 1)`.

A função `gauss` recebe como parâmetros:
 - `vector<bitset<M>> a`: um vector de bitsets, representando as equações do sistema. Cada bitset tem tamanho $M$, onde o bit $j$ do bitset $i$ representa o coeficiente da variável $j$ na equação $i$. A última posição do bitset $i$ representa o resultado da equação $i$.
 - `n` e `m`: inteiros representando o número de equações e variáveis, respectivamente.
 - `bitset<M> &ans`: um bitset de tamanho $M$, que será preenchido com a solução do sistema, caso exista.

A função retorna:
- `0`: se o sistema não tem solução.
- `1`: se o sistema tem uma única solução.
- `INF`: se o sistema tem infinitas soluções. Nesse caso, as variáveis em que `where[i] == -1` são as variáveis livres. Note que, pela natureza de $\mathbb{Z}_2$, o sistema não terá de fato infinitas soluções, mas sim $2^L$ soluções, onde $L$ é o número de variáveis livres.

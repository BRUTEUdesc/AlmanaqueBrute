# [Busca Binária Paralela](busca_binaria_paralela.cpp)

Faz a busca binária para múltiplas consultas quando a busca binária é muito pesada. A complexidade é $\mathcal{O}((N+Q) \log(N) \cdot \mathcal{O}(F))$, onde $N$ é o tamanho do espaço de busca, $Q$ é o número de consultas, e $\mathcal{O}(F)$ é o custo de avaliação da função.

Para cada consulta $i$, `solve(q, lo, hi, reset, apply, check)` retorna o menor $x \in [lo, hi]$ tal que `check(i)` é verdadeiro depois de aplicar os eventos $lo, \ldots, x$ (ou $hi + 1$ se não existir). A cada uma das $\mathcal{O}(\log N)$ rodadas, a estrutura é limpa com `reset()` e os eventos são reaplicados em ordem com `apply(x)`.

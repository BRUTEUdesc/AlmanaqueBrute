# [Floor Values](floor_values.cpp)

Código para encontrar todos os $\mathcal{O}(\sqrt{n})$ valores distintos de $\left\lfloor \frac{n}{i} \right\rfloor$ para $i = 1, 2, \ldots, n$.

Útil para computar, dentre outras coisas, os seguintes somatórios:

- Somatório de $\left\lfloor \frac{n}{i} \right\rfloor$ para $i = 1, 2, \ldots, n$.

- Somatório de $\sigma(i)$ para $i = 1, 2, \ldots, n$, onde $\sigma(i)$ é a soma dos divisores de $i$.
    - Usa o fato de que um número $i$ é divisor de exatamente $\left\lfloor \frac{n}{i} \right\rfloor$ números entre $1$ e $n$.
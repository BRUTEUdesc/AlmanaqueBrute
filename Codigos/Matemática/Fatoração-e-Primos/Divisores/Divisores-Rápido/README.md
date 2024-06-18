# [Divisores Rápido](get_divs.cpp)

Algoritmo que obtém todos os divisores de um número em $\mathcal{O}(\text{d(X)})$, onde $d(X)$ é a quantidade de divisores do número. Geralmente, para um número $X$, dizemos que a quantidade de divisores é $\mathcal{O}(\sqrt[3]{X})$.

De fato, para números até $10^{88}$, é verdade que $d(n) < 3.6 \cdot \sqrt[3]{n}$.

**Obs**: Usar algum código de fatoração presente nesse almanaque para obter os fatores do número.
- `Crivo/Crivo-Linear/linear_sieve.cpp` tem uma função de fatoração em $\mathcal{O}(\log X)$.
- `Fatores/Fatoração-Rápida/fast_factorize.cpp` tem uma função de fatoração em tempo médio $\mathcal{O}(\log X)$ que aceita até inteiros de 64 bits.
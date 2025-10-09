# [Dirichlet Convolution Prefix](dirichlet_convolution_prefix.cpp)

Dadas duas funções aritméticas $f$ e $g$ com valores computados para $1 \le i \le N^{\frac{2}{3}}$, além de seus prefixos de soma $F$ e $G$ com valores computados para todo $\left\lfloor \frac{N}{i} \right\rfloor$ com $1 \le i \le N^{\frac{1}{3}}$, obtém-se o vetor $H$ tal que
$H_i = \sum_{j=1}^{\lfloor \frac{n}{i} \rfloor} h(j)$
para todo $1 \le i \le N^{\frac{1}{3}}$ em $\mathcal{O}(N^{\frac{2}{3}})$, onde $h(n) = \sum_{d \mid n} f(d) \cdot g(\lfloor \tfrac{n}{d} \rfloor)$ é a convolução de Dirichlet de $f$ com $g$. Para atingir essa complexidade, inicialize a estrutura com $T = N^{2/3}$.

Para obter os demais valores de $H$ (para $1 \le i \le N^{\frac{2}{3}}$) utilize a [convolução de Dirichlet linear](../Dirichlet-Convolution/dirichlet_convolution.cpp).

O código usa a primitiva `Mint` para realizar operações modulares de forma eficiente.

## Funções utilizadas no método `Solve`

- `f(x)`: retorna o valor de $f(x)$ em $\mathcal{O}(1)$.
- `g(x)`: retorna o valor de $g(x)$ em $\mathcal{O}(1)$.
- `F(x)`: retorna o valor de $\sum_{i=1}^{\lfloor \frac{n}{x} \rfloor} f(i)$ em $\mathcal{O}(1)$.
- `G(x)`: retorna o valor de $\sum_{i=1}^{\lfloor \frac{n}{x} \rfloor} g(i)$ em $\mathcal{O}(1)$.

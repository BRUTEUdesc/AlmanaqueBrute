# [Dirichlet Convolution Prefix](dirichlet_convolution_prefix.cpp)

Dadas duas funções aritméticas $f$ e $g$ com seus valores computados para $1 \le i \le N ^ {\frac{2}{3}}$; e seus prefixos de soma $F$, $G$ com valores computados para todo $\left\lfloor   \frac{N}{i}  \right\rfloor$  com $1 \leq i \leq N ^ {\frac{1}{3}}$, obtém o vetor $H$: 
$$H_{i} = \sum_{j=1}^{\bigl\lfloor\frac{n}{i} \bigr\rfloor} h(j)$$
para todo $1 \leq i \leq N ^ {\frac{1}{3}}$ em $O(N ^ {\frac{2}{3}})$.  Sendo  $h(n) = \sum_{d \mid n} f(d) * g\left(\left\lfloor  \frac{n}{d}  \right\rfloor\right)$, ou seja, a convolução de Dirichlet de $f$ com $g$. Para atingir essa complexidade, deve-se inicializar a estrutura com $T = N^{\frac{2}{3}}$.

Para obter os demais valores de $H$ (para $1 \leq i \leq N ^ {\frac{2}{3}}$) basta utilizar a [convolução de Dirichlet linear](../Dirichlet-Convolution/dirichlet_convolution.cpp).

O código usa a primitiva Mint para realizar operações modulares de forma eficiente.

## Funções para serem usadas no método `Solve`

* f(x): função que retorna o valor de $f(x)$ em $O(1)$. 
* g(x): função que retorna o valor de $g(x)$ em $O(1)$.
* F(x): função que retorna o valor de $\sum_{i=1}^{\lfloor \frac{n}{x} \rfloor} f(i)$ em $O(1)$. 
* G(x): função que retorna o valor de $\sum_{i=1}^{\lfloor \frac{n}{x} \rfloor} g(i)$ em $O(1)$.

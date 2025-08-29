# [Dirichlet Convolution Prefix](dirichlet_convolution_prefix.cpp)

Calcula o vetor $H$ tal que $H[\lfloor \frac{n}{i}\rfloor] = \sum_{j=1}^{\lfloor
\frac{n}{i} \rfloor} h[j]$ onde $h$ é calculado a partir de $f$ e $g$ com $h[n]
= \sum_{d \mid n} f[d] \cdot g\!\left(\tfrac{n}{d}\right)$, ou seja, a
convolução de Dirichlet de $f$ com $g$.

O algoritmo calcula $H[\lfloor \frac{n}{i}\rfloor]$ para todos os valores possíveis de $\lfloor n / i \rfloor$ com $1 \le i \le N^{1/3}$ em $\mathcal{O}(N^{2/3})$. Para obter os demais $N^{2/3}$ valores, basta calcular
$H[i] = \sum_{j=1}^{i} h[j]$ usando soma de prefixo, onde $h$ pode ser calculado usando a convolução de Dirichlet linear.

Para atingir essa complexidade, deve-se inicializar a estrutura com $T = N^{\frac{2}{3}}$.

O código usa da primitiva Mint para realizar operações modulares de forma eficiente.

## Funções para serem usadas no método `Solve`

* f(x): função que retorna o valor de $f[x]$.
* g(x): função que retorna o valor de $g[x]$.
* F(x): função que retorna o valor de $\sum_{i=1}^{\lfloor \frac{n}{x} \rfloor} f[i]$.
* G(x): função que retorna o valor de $\sum_{i=1}^{\lfloor \frac{n}{x} \rfloor} g[i]$.

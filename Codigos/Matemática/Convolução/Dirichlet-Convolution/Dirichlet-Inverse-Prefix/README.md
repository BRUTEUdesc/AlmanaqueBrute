# [Dirichlet Inverse Prefix](dirichlet_inverse_prefix.cpp)

Dadas três funções aritméticas $f$, $F$ e $f^{-1}$ com valores computados para $1 \le i \le N^{\frac{2}{3}}$, em que $F(i) = \sum_{j=1}^{i} f(j)$ e $f^{-1}$ é a inversa de Dirichlet de $f$, obtém-se
$F^{-1}(\lfloor \tfrac{n}{i} \rfloor) = \sum_{j=1}^{\lfloor \frac{n}{i} \rfloor} f^{-1}(j)$
para todo $1 \le i \le N^{\frac{1}{3}}$ em $\mathcal{O}(N^{\frac{2}{3}})$. Para os demais $N^{\frac{2}{3}}$ valores, basta calcular
$F^{-1}(i) = \sum_{j=1}^{i} f^{-1}(j)$ usando soma de prefixo.

Para atingir essa complexidade, inicialize a estrutura com $T = N^{\frac{2}{3}}$ e realize as pré-computações necessárias para que todas as funções auxiliares respondam em $\mathcal{O}(1)$.

O código utiliza a primitiva `Mint` para realizar operações modulares de forma eficiente.

## Funções utilizadas no método `Solve`

- `f(x)`: retorna o valor de $f(x)$.
- `F(x)`: retorna o valor de $\sum_{j=1}^{x} f(j)$.
- `g(x)`: retorna o valor de $f^{-1}(x)$.

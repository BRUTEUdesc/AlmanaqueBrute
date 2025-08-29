# [Dirichlet Inverse Prefix](dirichlet_inverse_prefix.cpp)

Calcula o vetor $F^{-1}$ tal que
$F^{-1}[\lfloor n / i \rfloor] = \sum_{j=1}^{\lfloor n / i \rfloor} f^{-1}[j]$,
onde conhecemos os valores de $f[i]$ e $F[i] = \sum_{j=1}^{i} f[j]$ para todos os $i$ possíveis.

Aqui $f^{-1}$ é a inversa de Dirichlet de $f$.

O algoritmo calcula $F^{-1}[\lfloor n / i \rfloor]$ para todos os valores possíveis de $\lfloor n / i \rfloor$ com $1 \le i \le N^{1/3}$ em $\mathcal{O}(N^{2/3})$. Para obter os demais $N^{2/3}$ valores, basta calcular
$F^{-1}[i] = \sum_{j=1}^{i} f^{-1}[j]$ usando soma de prefixo.

Para atingir essa complexidade, deve-se inicializar a estrutura com $T = N^{2/3}$ e realizar as pré-computações necessárias de modo que todas as funções auxiliares possam ser obtidas em $\mathcal{O}(1)$.

O código utiliza a primitiva `Mint` para realizar operações modulares de forma eficiente.

## Funções para serem usadas no método `Solve`

- `f(x)`: retorna o valor de $f[x]$.
- `F(x)`: retorna o valor de $\sum_{j=1}^{x} f[j]$.
- `g(x)`: retorna o valor de $f^{-1}[x]$.


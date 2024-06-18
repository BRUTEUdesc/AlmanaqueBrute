# [Eliminação Gaussiana](gauss.cpp)

Método de eliminação gaussiana para resolução de sistemas lineares com coeficientes reais, a complexidade é $\mathcal{O}(n^3)$.

A função `gauss` recebe como parâmetros:
 - `vector<vector<double>> a`: uma matriz $N \times (M + 1)$, onde $N$ é o número de equações e $M$ é o número de variáveis, a última coluna de `a` deve conter o resultado das equações.
 - `vector<double> &ans`: um vetor de tamanho $M$, que será preenchido com a solução do sistema, caso exista.

A função retorna:
- `0`: se o sistema não tem solução.
- `1`: se o sistema tem uma única solução.
- `INF`: se o sistema tem infinitas soluções. Nesse caso, as variáveis em que `where[i] == -1` são as variáveis livres.


# [Crivo de Eratóstenes Linear](linear_sieve.cpp)

Crivo de Eratóstenes para encontrar os primos até um limite $P$, mas com complexidade $\mathcal{O}(P)$.

- `vector<bool> is_prime` é um vetor que diz se um número é primo ou não.
- `int cnt` é o número de primos encontrados.
- `int primes[P]` é um vetor com `cnt` os primos encontrados.
- `int lpf[P]` é o menor fator primo de cada número (usado para fatoração).

A função `Sieve::factorize()` fatora um número $N$ em tempo $\mathcal{O}(\log N)$.

**Obs**: Não esquecer de chamar `Sieve::build()` antes de usar.
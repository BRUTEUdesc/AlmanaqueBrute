# Primos

Algortimos relacionados a números primos.

# [Crivo de Eratóstenes](sieve.cpp)
Computa a primalidade de todos os números até N, quase tão rápido quanto o crivo linear.

- Complexidade de tempo: $\mathcal{O}(N * log(log(N)))$

Demora 1 segundo para LIM igual a $3 * 10^7$.

# [Miller-Rabin](miller_rabin.cpp)
Teste de primalidade garantido para números até $10^24$.

- Complexidade de tempo: $\mathcal{O}(log(N))$

# [Teste Ingênuo](naive_is_prime.cpp)
Computa a primalidade de um número N.

- Complexidade de tempo: $\mathcal{O}(\sqrt{N})$

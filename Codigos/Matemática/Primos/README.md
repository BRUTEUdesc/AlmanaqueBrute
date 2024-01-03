# Primos

*Read in [English](README.en.md)*

# [Crivo de Eratóstenes](sieve.cpp)
Computa a primalidade de todos os números até N, quase tão rápido quanto o crivo linear.

- Complexidade de tempo: O(N * log(log(N)))

Demora 1 segundo para LIM igual a $3 * 10^7$.

# [Miller-Rabin](miller_rabin.cpp)
Teste de primalidade garantido para números menores do que $2^64$.

- Complexidade de tempo: O(log(N))

# [Teste Ingênuo](naive_is_prime.cpp)
Computa a primalidade de um número N.

- Complexidade de tempo: $O(N^(1/2))$

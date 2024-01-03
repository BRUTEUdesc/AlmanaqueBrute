# Fatoração

*Read in [English](README.en.md)*

# [Fatoração Simples](naive_factorize.cpp)
Fatora um número N.

- Complexidade de tempo: $O(\sqrt n )$

# [Crivo Linear](linear_sieve_factorize.cpp)
Pré-computa todos os fatores primos até MAX.
Utilizado para fatorar um número N menor que MAX.

- Complexidade de tempo: Pré-processamento O(MAX)
- Complexidade de tempo: Fatoraração O(quantidade de fatores de N)
- Complexidade de espaço: O(MAX)

# [Fatoração Rápida](fast_factorize.cpp)
Utiliza Pollar-Rho e Miller-Rabin (ver em Primos) para fatorar um número N.

- Complexidade de tempo: $O(N^{1/4} \cdot log(N))$

# [Pollard-Rho](pollard-rho.cpp)
Descobre um divisor de um número N.

- Complexidade de tempo: $O(N^{1/4} \cdot log(N))$
- Complexidade de espaço: $O(N^{1/2})$

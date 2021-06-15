# Fatoração

*Read in [English](README.en.md)*

# [Fatoração Simples](naive_factorize.cpp)
Fatora um número N.
* Complexidade de tempo: O(N^(1/2))

# [Fatoração Rápida](fast_factorize.cpp)
Utiliza Pollar-Rho e Miller-Rabin (ver em Primos) para fatorar um número N.
* Complexidade de tempo: O(N^(1/4) * log(N))

# [Pollar-Rho](pollard-rho.cpp)
Descobre um divisor de um número N.
* Complexidade de tempo: O(N^(1/4) * log(N))
* Complexidade de espaço: O(N^(1/2))

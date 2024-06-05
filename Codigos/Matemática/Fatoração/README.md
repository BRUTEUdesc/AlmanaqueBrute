# Fatoração

<!-- DESCRIPTION -->
Algortimos para fatorar um número.
<!-- DESCRIPTION -->

# [Fatoração Simples](naive_factorize.cpp)
Fatora um número N.

- Complexidade de tempo: $\mathcal{O}(\sqrt n)$

# [Crivo Linear](linear_sieve_factorize.cpp)
Pré-computa todos os fatores primos até MAX.
Utilizado para fatorar um número N menor que MAX.

- Complexidade de tempo: Pré-processamento $\mathcal{O}(\text{MAX})$
- Complexidade de tempo: Fatoraração $\mathcal{O}(\text{quantidade de fatores de N})$
- Complexidade de espaço: $\mathcal{O}(\text{MAX})$

# [Fatoração Rápida](fast_factorize.cpp)
Utiliza Pollar-Rho e Miller-Rabin (ver em Primos) para fatorar um número N.

- Complexidade de tempo: $\mathcal{O}(N^{1/4} \cdot \log N))$

# [Pollard-Rho](pollard-rho.cpp)
Descobre um divisor de um número N.

- Complexidade de tempo: $\mathcal{O}(\sqrt[4]{N} \cdot \log N)$
- Complexidade de espaço: $\mathcal{O}(\sqrt N)$

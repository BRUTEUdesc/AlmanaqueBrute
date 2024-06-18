# [Fatoração Rápida](fast_factorize.cpp)

Algoritmo que combina o Crivo de Eratóstenes Linear, Miller-Rabin e Pollard Rho para fatorar um número $X$ em tempo médio $\mathcal{O}(\log X)$, no pior caso pode ser $\mathcal{O}(\sqrt[4]{X} \cdot \log X)$, mas na prática é seguro considerar $\mathcal{O}(\log X)$.

Esse código deve ser usado quando se deseja fatorar números $> 10^7$, por exemplo. Caso os números não sejam tão grandes assim, usar apenas o Crivo de Eratóstenes Linear sozinho é mais prático.

**Obs**: Usa três outros códigos desse Almanaque da seção Matemática:
- `Crivo/Crivo-Linear/linear_sieve.cpp`
- `Teste-Primalidade/Miller-Rabin/miller_rabin.cpp`-
- `Pollard-Rho/pollard_rho.cpp`.
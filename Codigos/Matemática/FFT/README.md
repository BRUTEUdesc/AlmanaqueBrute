# [Transformada Rápida de Fourier](fft.cpp)

<!-- DESCRIPTION -->
Algoritmo que computa a transformada rápida de fourier para convolução de polinômios.
<!-- DESCRIPTION -->

Computa convolução (multiplicação) de polinômios.

- Complexidade de tempo (caso médio): $\mathcal{O}(N * log(N))$
- Complexidade de tempo (considerando alto overhead): $\mathcal{O}(n * log^2(n) * log(log(n)))$

Garante que não haja erro de precisão para polinômios com grau até $3 * 10^5$ e constantes até $10^6$.

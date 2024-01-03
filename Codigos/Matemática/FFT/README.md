# [Transformada rápida de Fourier](fft.cpp)

*Read in [English](README.en.md)*

Computa multiplicação de polinômio.

- Complexidade de tempo (caso médio): O(N * log(N))
- Complexidade de tempo (considerando alto overhead): $O(n * log^2(n) * log(log(n)))$

Garante que não haja erro de precisão para polinômios com grau até $3 * 10^5$ e constantes até $10^6$.
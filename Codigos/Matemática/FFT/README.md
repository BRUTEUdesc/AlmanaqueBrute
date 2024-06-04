# [Transformada Rápida de Fourier](fft.cpp)

Algoritmo que computa a Transformada Rápida de Fourier para convolução de polinômios.

Computa convolução (multiplicação) de polinômios em $\mathcal{O}(n * log(n))$, sendo $n$ a soma dos graus dos polinômios.

Testado e sem erros de precisão com polinômios de grau até $3 * 10^5$ e constantes até $10^6$. Para convolução de inteiros sem erro de precisão, consultar a seção de NTT.

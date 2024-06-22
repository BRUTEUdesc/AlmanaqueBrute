# [Or Convolution] (or-convolution.cpp)

Calcula o vector `C` a partir de `A` e `B` tal que C[i] = $\sum_{\substack{(j | k) == i}} A[j] \cdot B[k]$ em $\mathcal{O}(2^N \cdot N)$
onde $2^N$ é a menor potência de $2$ maior ou igual que o tamanho de ambos os vetores `A` e `B`.

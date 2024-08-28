# [XOR Convolution](xor_convolution.cpp)

Calcula o vetor $C$ a partir de $A$ e $B$ tal que $C[i] = \sum_{\substack{(j \oplus k) = i}} A[j] \cdot B[k]$ em $\mathcal{O}(N \cdot \log N)$

# [LCM Convolution](lcm_convolution.cpp)

Calcula o vetor $C$ a partir de $A$ e $B$ $C[i] = \sum_{\substack{lcm(j, k) = i}} A[j] \cdot B[k]$ em $\mathcal{O}(N \cdot \log N)$.

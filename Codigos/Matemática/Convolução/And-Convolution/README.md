# [AND Convolution](and-convolution.cpp)

Calcula o vetor $C$ a partir de $A$ e $B$ onde $C[i] = \sum_{\substack{(j \land k) = i}} A[j] \cdot B[k]$ em $\mathcal{O}(N \cdot \log N)$.

Obs: $\land$ representa o bitwise and.

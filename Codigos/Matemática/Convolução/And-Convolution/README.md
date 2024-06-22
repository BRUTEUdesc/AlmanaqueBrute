# [And Convolution] (and-convolution.cpp)

Calcula o vetor $C$ a partir de $A$ e $B$ onde $$ C[i] = \sum_{\substack{(j \text{\&} k) = i}} A[j] \cdot B[k] $$ em $\mathcal{O}(2^N \cdot N)$
onde $2^N$ é a menor potência de $2$ maior ou igual que o tamanho de ambos os vetores $A$ e $B$.

# [Subset Convolution](subset_convolution.cpp)

Calcula o vetor $C$ a partir de $A$ e $B$ tal que $C[i] = \sum_{\substack{(j \| k) = i}, \substack{(j \land k) = 0}} A[j] \cdot B[k]$ em $\mathcal{O}(N \cdot \log^2 N)$

Obs: $\land$ representa o bitwise and e $\|$ representa o bitwise or.

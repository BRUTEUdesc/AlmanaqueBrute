#[Gcd-Convolution] (gcd-convolution.cpp)

Calcula o vetor `C` a partir de `A` e `B` C[i] = $\sum_{\substack{gcd(j, k) == i}} A[j] \cdot B[k]$ em $\mathcal{O}(N \cdot log N)$.
onde $N$ = `max(A.size(), B.size())`

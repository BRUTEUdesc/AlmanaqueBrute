# [Mo](mo.cpp)

Resolve queries complicadas Offline de forma rápida.  

É preciso manter uma estrutura que adicione e remova elementos nas extremidades de um range (tipo janela).

A complexidade do `run` é $\mathcal{O}(Q * B + N^2/B)$, onde $B$ é o tamanho do bloco.

Para $B = \sqrt{N}$, a complexidade é $\mathcal{O}((N + Q) * \sqrt{N})$.

Para $B = N / \sqrt Q$, a complexidade é $\mathcal{O}(N * \sqrt{Q})$.

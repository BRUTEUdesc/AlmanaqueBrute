# Floyd-Warshall

Algoritmo que encontra o menor caminho entre todos os pares de vértices de um grafo com pesos em $\mathcal{O}(N^3)$.

A ideia do algoritmos é: para cada vértice $k$, passamos por todos os pares de vértices $(i, j)$ e verificamos se é mais curto passar por $k$ para ir de $i$ a $j$ do que o caminho atual de $i$ a $j$. Se for, atualizamos o caminho.
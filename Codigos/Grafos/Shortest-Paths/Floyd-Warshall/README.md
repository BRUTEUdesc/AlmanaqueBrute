# [Floyd-Warshall](floyd_warshall.cpp)

Algoritmo que encontra o menor caminho entre todos os pares de nodos de um grafo com pesos em $\mathcal{O}(N^3)$.

A ideia do algoritmo é: para cada nodo $k$, passamos por todos os pares de nodos $(i, j)$ e verificamos se é mais curto passar por $k$ para ir de $i$ a $j$ do que o caminho atual de $i$ a $j$. Se for, atualizamos o caminho.
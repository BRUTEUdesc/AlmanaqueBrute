# Dijkstra

Computa o menor caminho entre nós de um grafo.

## Dijkstra 1:1

Dado dois nós u e v, computa o menor caminho de u para v.

Complexidade de tempo: O((E + V) * log(E))

## Dijkstra 1:N

Dado um nó u, computa o menor caminho de u para todos os nós.

Complexidade de tempo: O((E + V) * log(E))

## Dijkstra N:N

Computa o menor caminho de todos os nós para todos os nós

Complexidade de tempo: O(V * ((E + V) * log(E)))

## Dijkstra Dense

Dado um nó u, computa o menor caminho de u para todos os nós.

Usa uma matriz de adjacência para representar o grafo.

Complexidade ótima para grafos densos.

Complexidade de tempo: O(V^2)

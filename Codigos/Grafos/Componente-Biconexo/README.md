# [Componente Biconexo](componente_biconexo.cpp)

Algoritmo que encontra as componentes biconexas de um grafo não direcionado.
O algoritmo resolve isso em $\mathcal{O}(N + M)$, onde \$N\$ é o número de vértices e \$M\$ é o número de arestas do grafo.

Cada componente biconexo é armazenado no vetor `comp`.
Para cada nó \$u\$ do grafo original, é possível saber o seu componente acessando `who[u]`.


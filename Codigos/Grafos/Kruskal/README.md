# [Kruskal](kruskal.cpp)

Algoritimo que utiliza DSU (Disjoint Set Union, descrita na seção de Estrutura de Dados) para encontrar a MST (Minimum Spanning Tree) de um grafo em $\mathcal{O}(E \log E)$.

A Minimum Spanning Tree é a árvore geradora mínima de um grafo, ou seja, um conjunto de arestas que conecta todos os vértices do grafo com o menor custo possível.

Propriedades importantes da MST:

- É uma árvore! :O
- Entre quaisquer dois nodos $u$ e $v$ do grafo, a MST minimiza a maior aresta no caminho de $u$ a $v$.

Ideia do Kruskal: ordenar as arestas do grafo por peso e, para cada aresta, adicionar ela à MST se ela não forma um ciclo com as arestas já adicionadas.
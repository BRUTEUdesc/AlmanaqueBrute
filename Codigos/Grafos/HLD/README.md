# [Heavy-Light Decomposition](hld.cpp)

Técnica utilizada para decompor uma árvore em cadeias, e assim realizar operações de caminho e subárvore em $\mathcal{O}(\log n \cdot g(n))$, onde $g(n)$ é a complexidade da operação. Esta implementação suporta queries de soma e update de soma/atribuição, pois usa a estrutura de dados `Segment Tree Lazy` desse almanaque, fazendo assim com que updates e consultas sejam  $\mathcal{O}(\log^2 n)$. A estrutura (bem como a operação feita nela) pode ser facilmente trocada, basta alterar o código da `Segment Tree Lazy`, ou ainda, utilizar outra estrutura de dados, como uma `Sparse Table`, caso você tenha queries de mínimo/máximo sem updates, por exemplo.

A decomposição pode ser feita com os valores estando tanto nos vértices quanto nas arestas, consulte os métodos `build` do código para mais detalhes.

A construção da HLD é feita em $\mathcal{O}(n + b(n))$, onde $b(n)$ é a complexidade de construir a estrutura de dados utilizada.
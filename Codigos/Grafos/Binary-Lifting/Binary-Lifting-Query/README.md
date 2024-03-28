# [Binary Lifting Query](binary_lifting_query_nodo.cpp)

Binary Lifting em que, além de queries de ancestrais, podemos fazer queries em caminhos. Seja $f(u, v)$ uma função que retorna algo sobre o caminho entre $u$ e $v$, como a soma dos valores dos nodos ou máximo valor do caminho, `st[u][i]` é o valor de $f(par[u], up[u][i])$, em que `up[u][i]` é o $2 ^ i$-ésimo ancestral de `u` e `par[u]` é o pai de `u`. A função $f$ deve ser associativa e comutativa.

A construção é $\mathcal{O}(n \log n)$, e é possível consultar em $\mathcal{O}(\log n)$ pelo valor de $f(u, v)$, em que $u$ e $v$ são nodos do grafo, através do método `query`. Também computa LCA e $k$-ésimo ancestral em $\mathcal{O}(\log n)$.

**Obs**: os valores precisam estar nos **nodos** e não nas arestas, para valores nas arestas verificar o `Binary Lifting Query Aresta`.
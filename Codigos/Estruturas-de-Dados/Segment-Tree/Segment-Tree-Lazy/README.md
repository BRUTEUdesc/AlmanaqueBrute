# [Segment Tree Lazy](seg_tree_lazy.cpp)

Lazy Propagation é uma técnica para updatar a Segment Tree que te permite fazer updates em intervalos, não necessariamente pontuais. Esta implementação responde consultas de soma em intervalo e updates de soma ou atribuição em intervalo, veja o método `update`.

A construção é $\mathcal{O}(n)$ e as operações de consulta e update são $\mathcal{O}(log(n))$.

**Dica**: A Seg Tree usa $4 \cdot n$ de memória pois cada nodo $p$ tem seus filhos $2 \cdot p$ (filho esquerdo) e $2 \cdot p + 1$ (filho direito). Há uma forma de indexar os nodos que usa $2 \cdot n$ de memória. Dado um nodo $p$ que representa o intervalo $[l, r]$, seu filho esquerdo é $p+1$ (e representa o intervalo $[l, mid]$) e seu filho direito é $p+2 \cdot (mid-l+1)$ (e representa o intervalo $[mid+1, r]$), onde $mid = (l+r)/2$.
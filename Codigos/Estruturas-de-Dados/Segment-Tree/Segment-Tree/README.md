# [Segment Tree](seg_tree.cpp)

Implementação padrão de Segment Tree, suporta operações de consulta em intervalo e update pontual. Está implementada para soma, mas pode ser facilmente modificada para outras operações. A construção é $\mathcal{O}(n)$ e as operações de consulta e update são $\mathcal{O}(log(n))$.

**Dica**: A Seg Tree usa $4 \cdot n$ de memória pois cada nodo $p$ tem seus filhos $2 \cdot p$ (filho esquerdo) e $2 \cdot p + 1$ (filho direito). Há uma forma de indexar os nodos que usa $2 \cdot n$ de memória. Dado um nodo $p$ que representa o intervalo $[l, r]$, seu filho esquerdo é $p+1$ (e representa o intervalo $[l, mid]$) e seu filho direito é $p+2 \cdot (mid-l+1)$ (e representa o intervalo $[mid+1, r]$), onde $mid = (l+r)/2$.
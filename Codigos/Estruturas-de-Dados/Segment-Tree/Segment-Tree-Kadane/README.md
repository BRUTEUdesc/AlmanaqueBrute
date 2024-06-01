# [Seg Tree Kadane](seg_tree_kadane.cpp)

Implementação de uma Segment Tree que suporta update pontual e query de soma máxima de um subarray em um intervalo. A construção é $\mathcal{O}(n)$ e as operações de consulta e update são $\mathcal{O}(log(n))$.

É uma Seg Tree normal, a magia está na função `merge` que é a função que computa a resposta do nodo atual. A ideia do `merge` da Seg Tree de Kadane de combinar respostas e informações já computadas dos filhos é muito útil e pode ser aplicada em muitos problemas.

**Obs**: não considera o subarray vazio como resposta.

**Dica**: A Seg Tree usa $4 \cdot n$ de memória pois cada nodo $p$ tem seus filhos $2 \cdot p$ (filho esquerdo) e $2 \cdot p + 1$ (filho direito). Há uma forma de indexar os nodos que usa $2 \cdot n$ de memória. Dado um nodo $p$ que representa o intervalo $[l, r]$, seu filho esquerdo é $p+1$ (e representa o intervalo $[l, mid]$) e seu filho direito é $p+2 \cdot (mid-l+1)$ (e representa o intervalo $[mid+1, r]$), onde $mid = (l+r)/2$.
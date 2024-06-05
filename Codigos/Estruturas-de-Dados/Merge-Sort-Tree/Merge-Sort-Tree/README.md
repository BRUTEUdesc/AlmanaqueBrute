# [Merge Sort Tree](mergesort_tree.cpp)

Árvore muito semelhante a uma Segment Tree, mas ao invés de armazenar um valor em cada nodo, armazena um vetor ordenado. Permite realizar consultas do tipo: `count(L, R, A, B)` que retorna quantos elementos no intervalo $[L, R]$ estão no intervalo $[A, B]$ em $\mathcal{O}(\log^2 n)$. Em outras palavras, count(L, R, A, B) retorna quantos elementos $x$ existem no intervalo $[L, R]$ tal que $A \leq x \leq B$.

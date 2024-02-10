# [DSU](dsu.cpp)

Estrutura que mantém uma coleção de conjuntos e permite as operações de unir dois conjuntos e verificar em qual conjunto um elemento está, ambas em $\mathcal{O}(1)$ amortizado. O método `find` retorna o representante do conjunto que contém o elemento, e o método `unite` une os conjuntos que contém os elementos dados, retornando `true` se eles estavam em conjuntos diferentes e `false` caso contrário.

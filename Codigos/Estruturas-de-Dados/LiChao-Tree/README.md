# [LiChao Tree](lichao_tree.cpp)

<!-- DESCRIPTION -->
Uma árvore de Funções. Retorna o F(x) máximo em um ponto X.
<!-- DESCRIPTION -->

Para retornar o minimo deve-se inserir o negativo da função e pegar o negativo do resultado.

Está pronta para usar função linear do tipo F(x) = mx + b.

Funciona para funções com a seguinte propriedade, sejam duas funções f(x) e g(x), uma vez que f(x) ganha/perde de g(x), f(x) vai continuar ganhando/perdendo de g(x),
ou seja f(x) e g(x) se intersectam apenas uma vez.

* Complexidade de consulta : O(log(N))
* Complexidade de update: O(log(N))

# [LiChao Tree Sparse](lichao_tree_sparse.cpp)

O mesmo que a superior, no entanto suporta consultas com |x| <= 1e18.

* Complexidade de consulta : O(log(tamanho do intervalo))
* Complexidade de update: O(log(tamanho do intervalo))

# [LiChao Tree](lichao_tree.cpp)

Uma árvore de funções. Retorna o $f(x)$ máximo em um ponto $x$.

Para retornar o minimo deve-se inserir o negativo da função ($g(x) = -ax - b$) e pegar o negativo do resultado. Ou, alterar a função de comparação da árvore se souber mexer.

Funciona para funções com a seguinte propriedade, sejam duas funções $f(x)$ e $g(x)$, uma vez que $f(x)$ passa a ganhar/perder pra $g(x)$, $f(x)$ nunca mais passa a perder/ganhar pra $g(x)$. Em outras palavras, $f(x)$ e $g(x)$ se intersectam no máximo uma vez.

Essa implementação está pronta para usar função linear do tipo $f(x) = ax + b$.

Sendo $L$ o tamanho do intervalo, a complexidade de consulta e inserção de funções é $\mathcal{O}(log(L))$.
# [Seg Tree Kadani](seg_tree_kadani.cpp)

Implementação de uma Segment Tree que suporta update de soma em intervalo e query de soma máxima de um subarray em um intervalo. A construção é $\mathcal{O}(n)$ e as operações de consulta e update são $\mathcal{O}(log(n))$.

É uma Seg Tree normal, a magia está na função `merge` que é a função que combina as respostas dos filhos para computar a resposta do nodo atual. A ideia do `merge` de combinar respostas e informações já computadas dos filhos é muito útil e pode ser aplicada em muitos problemas.

**Obs**: não considera o subarray vazio como resposta.
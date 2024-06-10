# [Xor Trie](XorTrie.cpp)

Uma Trie que armazena os números em binario (do bit mais significativo para o menos). Permite realizar inserção de um número $X$ em $\mathcal{O}(\log X)$.

`max_xor(X)` retorna o número contido na Trie que tem maior Xor com o valor `X` e `min_xor(X)` retorna o número contido na Trie que tem menor Xor com o valor `X`. Note que o valor $X$ não precisa estar na Trie.

# [XOR Trie](XorTrie.cpp)

Uma Trie que armazena os números em binario (do bit mais significativo para o menos). Permite realizar inserção de um número $X$ em $\mathcal{O}(\log X)$. O inteiro `bits` no template da estrutura é a quantidade bits dos números você deseja considerar.

O método `max_xor(X)` retorna o número contido na Trie que tem maior XOR com o valor $X$ e `min_xor(X)` retorna o número contido na Trie que tem menor XOR com o valor $X$. Note que o valor $X$ não precisa estar na Trie. Ambos os métodos são $\mathcal{O}(\log X)$.

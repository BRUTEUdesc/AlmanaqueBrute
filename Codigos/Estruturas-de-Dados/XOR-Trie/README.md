# [XOR Trie](xor_trie.cpp)

Uma Trie que armazena os números em binario (do bit mais significativo para o menos). Permite realizar inserção de um número $X$ em $\mathcal{O}(\log X)$. O inteiro `bits` no template da estrutura é a quantidade bits dos números você deseja considerar.

O método `max_xor(X)` retorna o resultado do maior XOR de $X$ com algum número contido na Trie e `min_xor(X)` resultado do menor XOR de $X$ com algum número contido na Trie. Note que o valor $X$ não precisa estar na Trie. Ambos os métodos são $\mathcal{O}(\log X)$.

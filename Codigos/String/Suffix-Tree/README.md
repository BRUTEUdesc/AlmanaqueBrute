# [Suffix Tree](suffix_tree.cpp)

Constrói a árvore de sufixos de uma string $S$ em $\mathcal{O}(|S|)$. A árvore não é construída da forma clássica com o algoritmo de Ukkonen, mas sim utilizando do Suffix Automaton.

**Teorema**: a árvore de links do Suffix Automaton sobre uma string $S$, é a Suffix Tree de $\overline{S}$, onde $\overline{S}$ é a string $S$ reversa. Aqui não cabe provar esse teorema, basta crer.

Praticamente tudo do suffix automaton ainda vale aqui. Uma diferença é que `where[i]` agora diz em qual nodo da árvore o sufixo $s[i..|s|-1]$ está. E `lnk[i]` agora aponta para o maior **prefixo** de `i` que não está na mesma classe de equivalência que $i$.

Além disso, temos um vetor adicional `suff[i]` que diz se o nodo `i` é um sufixo da string original.

Por definição, `len[lca(u, v)]` diz o tamanho da maior substring que é prefixo de `u` e `v` ao mesmo tempo, ou seja, é o longest common prefix (LCP).

Ou seja, o que temos nesse código é o Suffix Automaton, mas que ao passar uma string pra ele, ele constrói o autômato da string reversa. As aplicações no código vão se basear no fato de que a árvore que temos é a Suffix Tree. Se usar com carinho, podemos usar tanto o autômato quanto a Suffix Tree ao mesmo tempo (só tem que lembrar que a string original está invertida no autômato, caso queira fazer processamento de alguma string ou algo assim).

Nesse código, a lista de adjacência da árvore está ordenada lexicograficamente, ou seja, se passarmos pela árvore em ordem de DFS, os nodos que estão marcados com `suff[u] = 1`, são os sufixos da string original ordenados lexicograficamente, ou seja, é o Suffix Array.

**Obs**: apesar do algoritmo de inserção de caractere funcionar de maneira online, todas aplicações no código requerem que a string seja passada de uma vez, e que não sejam feitos inserts adicionais.

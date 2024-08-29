# [Suffix Automaton](suffix_automaton.cpp)

Constrói o autômato de sufixos de uma string $S$ em $\mathcal{O}(|S|)$ de forma online.  

- `len[u]` é o tamanho da maior string na classe de equivalência de `u`. 
- `lnk[u]` é o nodo que representa o maior sufixo de `u` que não pertence a classe de equivalência de `u`.
- `to[u]` é um array que representa as possivéis transições de um nodo `u`.
- `cnt[u]` é um array que conta para cada classe de equivalência quantas ocorrências essas substrings tem.
- `where[i]` diz em qual nodo do autômato a substring $s[0..i]$ está.

Por definição, `len[lca(u, v)]` diz o tamanho da maior substring que é sufixo de `u` e `v` ao mesmo tempo, ou seja, é o longest common suffix.

Algumas aplicações estão no código, é importante notar que essas aplicações funcionam de maneira **offline**, ou seja, uma vez settada a string no autômato, não se deve fazer inserts adicionais de caracteres.

Para outras possíveis aplicações, consulte a Suffix Tree.
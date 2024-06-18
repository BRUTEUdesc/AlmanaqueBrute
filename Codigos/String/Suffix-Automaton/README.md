# [Suffix Automaton](suffix_automaton.cpp)

Constrói o autômato de sufixos de uma string $S$ em $\mathcal{O}(|S|)$ de forma online. 

- `len[u]` é o tamanho da maior string na classe de equivalência de `u`. 
- `lnk[u]` é o nodo que representa o maior sufixo de `u` que não pertence a classe de equivalência de `u`.
- `to[u]` é um array que representa as possivéis transições de um nodo `u`.

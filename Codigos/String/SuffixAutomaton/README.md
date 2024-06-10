# [Suffix Automaton](SuffixAutomaton.cpp)

Constrói o autômato de sufixos de uma string $S$ em $\mathcal{O}(|S|)$ de forma online. 
`len[v]` é o tamanho da maior string na classe de equivalência de `v`. 

`lnk[v]` é o nodo que representa o maior sufixo de `v` que não pertence a classe de equivalência de `v`.

`to[v]` é um array que representa as possivéis transições de um nodo v.



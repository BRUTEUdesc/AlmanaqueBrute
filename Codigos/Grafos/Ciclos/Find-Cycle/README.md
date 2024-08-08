# [Find Cycle](find_cycle.cpp)

Encontra um ciclo no grafo em $\mathcal{O}(|V| + |E|)$, retorna um vetor vazio caso nenhum ciclo seja encontrado. O método `build` possui uma flag que indica se o grafo em questão é direcionado ou não.

**Obs**: se o grafo for **não direcionado** e conter multi-arestas, o algoritmo pode não funcionar como esperado, por exemplo, se houverem duas arestas entre $u$ e $v$, o algoritmo não vai dizer que isso é um ciclo. Trate isso adequadamente.

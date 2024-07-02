# [DSU Offline](offline_dsu.cpp)

Algoritmo que utiliza o DSU com Rollback e Bipartido que permite adição e **remoção** de arestas. O algoritmo funciona de maneira offline, recebendo previamente todas as operações de adição e remoção de arestas, bem como todas as perguntas (de qualquer tipo, conectividade, bipartição, etc), e retornando as respostas para cada pergunta no retorno do método `solve`. Complexidade total $\mathcal{O}(Q \cdot (\log Q + \log N))$, onde $Q$ é o número de operações realizadas e $N$ é o número de nodos.

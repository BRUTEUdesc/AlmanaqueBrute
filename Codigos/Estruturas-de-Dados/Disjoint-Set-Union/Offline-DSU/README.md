# [DSU Offline](offline_dsu.cpp)

Algoritmo que utiliza o Full DSU (DSU com Rollback e Bipartido) que permite adição e **remoção** de arestas. O algoritmo funciona de maneira offline, recebendo previamente todas as operações de adição e remoção de arestas, bem como todas as perguntas (de qualquer tipo, conectividade, bipartição, etc), e retornando as respostas para cada pergunta no retorno do método `solve`. Complexidade total $\mathcal{O}(q\cdot(\log q + \log n))$, onde $q$ é o número de operações realizadas e $n$ é o número de nodos.

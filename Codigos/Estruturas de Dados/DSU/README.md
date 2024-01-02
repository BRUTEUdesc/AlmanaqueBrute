# Disjoint Set Union

*Read in [English](README.en.md)*

# [DSU Simples](dsu.cpp)
Estrutura que trata conjuntos.  
Verifica se dois itens pertencem a um mesmo grupo.

- Complexidade de tempo: O(1) amortizado.

Une grupos.

- Complexidade de tempo: O(1) amortizado.

# [DSU Bipartido](bipartite_dsu.cpp)
DSU para grafo bipartido, é possível verificar se uma aresta é possível antes de adicioná-la.  
Para todas as operações:

- Complexidade de tempo: O(1) amortizado.

# [DSU com Rollback](rollback_dsu.cpp)
Desfaz as últimas K uniões

- Complexidade de tempo: O(K).

É possivel usar um checkpoint, bastando chamar **rollback()** para ir até o último checkpoint.  
O rollback não altera a complexidade, uma vez que K <= queries.  
**Só funciona sem compressão de caminho**

- Complexidade de tempo: O(log(N))

# [DSU Completo](full_dsu.cpp)
DSU com capacidade de adicionar e remover vértices.  
**EXTREMAMENTE PODEROSO!**  
Funciona de maneira off-line, recebendo as operações e dando as respostas das consultas no retorno da função **solve()**

- Complexidade de tempo: O(Q * log(Q) * log(N)); Onde Q é o número de consultas e N o número de nodos

Roda em 0,6ms para 3 * 10⁵ queries e nodos com printf e scanf.  
Possivelmente aguenta 10⁶ em 3s


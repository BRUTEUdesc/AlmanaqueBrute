### PT-BR

# DSU Simples
Estrutura que trata conjuntos\
Verifica se dois itens pertencem a um mesmo grupo.
* Complexidade de tempo: O(1) amortizado.

Une grupos.
* Complexidade de tempo: O(1) amortizado.

# DSU Bipartido
DSU para grafo bipartido, é possível verificar se uma aresta é possível antes de adicioná-la.\
Para todas as operações:
* Complexidade de tempo: O(1) amortizado.

# DSU com Rollback
Desfaz as últimas K uniões
* Complexidade de tempo: O(K).

É possivel usar um checkpoint, bastando chamar rollback() para ir até o último checkpoint\
O rollback não altera a complexidade, uma vez que K <= queries.\
**Só funciona sem compressão de caminho**
* Complexidade de tempo: O(log(N))

# DSU Completo
DSU com capacidade de adicionar e remover vértices.\
**EXTREMAMENTE PODEROSO!**\
Funciona de maneira off-line, recebendo as operações e dando as respostas das consultas no retorno da função run
* Complexidade de tempo: O(Q * log(Q) * log(N)); Onde Q é o número de consultas e N o número de nodos

Roda em 0,6ms para 3 * 10^5 queries e nodos com printf e scanf\
Possivelmente aguenta 10^6 em 3s

### EN-US

# Simple DSU
Structure for handling sets\
Verifies if two itens belong to the same group.
* Time complexity: O(1) amortized

Unifies groups.
* Time complexity: O(1) amortized

# Bipartite DSU
DSU for bipartite graph, it's possible to verify if some edge is possible before adding it.\
For every operation
* Time complexity: O(1) amortized

# DSU with Rollback
Undo the last K unions
* Time complexity: O(K)

It's possible to use a checkpoint, then just call rollback() to go to the last checkpoint\
The rollback doesn't change the complexity, since K <= queries.\
**Only works without path compression**
* Time complexity: O(log(N))

# Complete DSU
DSU with capacity of adding and removing vertices.\
**EXTREMELY POWERFUL!**\
Works offline, receiving operations and giving the answers to the queries as return of the function run.
* Time complexity: O(Q * log(Q) * log(N)); Where Q is the number of queries and N the number of nodes.

Runs in 0,6ms for 3 * 10^5 queries and nodes with printf and scanf  
Possibly handles 10^6 in 3s.

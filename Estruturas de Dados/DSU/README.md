# DSU Comum
Estrutura que trata conjuntos\
Verifica se dois itens pertencem à um mesmo grupo em **O(1)** amortizado\
Une grupos em **O(1)** amortizado


# DSU Bipartido
DSU para grafo bipartido, é possível verificar se uma aresta é possível antes de adicioná-la\
Todas as operações em **O(1)** amortizado

# DSU com Rollback
DSU com rollback, desfaz as últimas K uniões em **O(K)**\
É possivel usar um checkpoint e daí basta chamar rollback() para ir até o último checkpoint\
O rollback não altera a complexidade, uma vez que **K** <= queries.\
**Só funciona sem compressão de caminho** \
Join, Get e Same em **O( log(N) )**

# DSU Completo
DSU com capacidade de adicionar e remover vértices\
**EXTREMAMENTE PODEROSO**\
Funciona de maneira off-line, vá adicionando as operações e receba as respostas das consultas no retorno da função run\
**O( m * log(m) * log(n) )** onde **m** é o  número de queries e **n** é o número de nodos\
Roda em 0,6 ms para 3*10⁵ queries e nodos com printf e scanf\
Possivelmente aguenta 10⁶ em 3s

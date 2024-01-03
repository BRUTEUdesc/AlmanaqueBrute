# [DSU com Rollback](rollback_dsu.cpp)
Desfaz as últimas K uniões

- Complexidade de tempo: O(K).

É possivel usar um checkpoint, bastando chamar **rollback()** para ir até o último checkpoint.  
O rollback não altera a complexidade, uma vez que K <= queries.  
**Só funciona sem compressão de caminho**

- Complexidade de tempo: O(log(N))
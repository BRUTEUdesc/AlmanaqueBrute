# 2-SAT  

Algoritmo que resolve problema do 2-SAT. No 2-SAT, temos um conjunto de variáveis booleanas e cláusulas lógicas, onde cada cláusula é composta por duas variáveis. O problema é determinar se existe uma configuração das variáveis que satisfaça todas as cláusulas. O problema se transforma em um problema de encontrar as componentes fortemente conexas de um grafo direcionado, que resolvemos em $\mathcal{O}(N + M)$ com o algoritmo de Kosaraju. Onde $N$ é o número de variáveis e $M$ é o número de cláusulas.  

A configuração da solução fica guardada no vetor `assignment`.

Em relação ao sinal, tanto faz se 0 liga ou desliga, apenas siga o mesmo padrão.

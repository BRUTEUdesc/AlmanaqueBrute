# [2-SAT](2_sat.cpp)

Algoritmo que resolve problema do 2-SAT. No 2-SAT, temos um conjunto de variáveis booleanas e cláusulas lógicas, onde cada cláusula é composta por duas variáveis. O problema é determinar se existe uma configuração das variáveis que satisfaça todas as cláusulas. O problema se transforma em um problema de encontrar as componentes fortemente conexas de um grafo direcionado, que resolvemos em $\mathcal{O}(N + M)$ com o algoritmo de Kosaraju. Onde $N$ é o número de variáveis e $M$ é o número de cláusulas.  

A configuração da solução fica guardada no vetor `assignment`.

Exemplos de uso:

- `sat.add_or(x, y)` $\Leftrightarrow (x \lor y)$
- `sat.add_or(~x, y)` $\Leftrightarrow (\lnot x \lor y)$
- `sat.add_impl(x, y)` $\Leftrightarrow (x \rightarrow y)$
- `sat.add_and(x, ~y)` $\Leftrightarrow (x \land \lnot y)$
- `sat.add_xor(x, y)` $\Leftrightarrow (x \lor y) \land \lnot (x \land y)$
- `sat.add_equals(x, y)` $\Leftrightarrow (x \land y) \lor (\lnot x \land \lnot y)$
# [Interval Tree](interval_tree.cpp) (Autoral)

**Por Rafael Granza de Mello**

Estrutura que trata intersecções de intervalos.

Capaz de retornar todos os intervalos que intersectam $[L, R]$. Contém métodos $insert({L, R, ID})$, $erase({L, R, ID})$, $overlaps(L, R)$ e $find({L, R, ID})$. É necessário inserir e apagar indicando tanto os limites quanto o ID do intervalo. Todas as operações são $\mathcal{O}(\log n)$, exceto $overlaps$ que é $\mathcal{O}(k + \log n)$, onde $k$ é o número de intervalos que intersectam $[L, R]$. Também podem ser usadas as operações padrões de um $std::set$.

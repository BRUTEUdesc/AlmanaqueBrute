
# [Interval Tree](interval_tree.cpp) (Autoral)

*Read in [English](README.en.md)*
*Por Rafael Granza de Mello*

Capaz de retornar todos os intervalos que intersectam [L, R]. **L e R inclusos**\
Contém funções insert({L, R, ID}), erase({L, R, ID}) , overlaps(L, R) e find({L, R, ID}).\
É necessário inserir e apagar indicando tanto os limites quanto o ID do intervalo.

* Complexidade de tempo: O( N * log(N) ).

Podem ser usadas as operações em Set: 
 * insert() 
 * erase() 
 * upper_bound() 
 * etc 

# Interval Tree (Raro)
Capaz de retornar todos os intervalos que intersectam [L, R] com overlaps(L, R). **L e R inclusos**\
insert({L, R, ID}), erase({L, R, ID}) , overlaps(L, R) e find({L, R, ID}) em **O( log(n) )**.\
É necessário inserir e apagar indicando tanto os limites quanto o ID do intervalo

# [Sparse Table](sparse_table.cpp)

*Read in [English](README.en.md)*

Responde consultas de maneira eficiente em um conjunto de dados estáticos.\
Realiza um pré-processamento para diminuir o tempo de cada consulta.
* Complexidade de tempo (Pré-processamento): O(N * log(N))
* Complexidade de tempo (Consulta para operações sem sobreposição amigável): O(N * log(N))
* Complexidade de tempo (Consulta para operações com sobreposição amigável): O(1)
* Complexidade de espaço: O(N * log(N))

Exemplo de operações com sobreposição amigável: max(), min(), gcd(), f(x, y) = x



# [Sparse Table](sparse_table.cpp)

*Read in [English](README.en.md)*

Responde consultas de maneira eficiente em um conjunto de dados estáticos.\
Realiza um pré-processamento para diminuir o tempo de cada consulta.

- Complexidade de tempo (Pré-processamento): $\mathcal{O}(N * log(N))$
- Complexidade de tempo (Consulta para operações sem sobreposição amigável): $\mathcal{O}(N * log(N))$
- Complexidade de tempo (Consulta para operações com sobreposição amigável): $\mathcal{O}(1)$
- Complexidade de espaço: $\mathcal{O}(N * log(N))$

Exemplo de operações com sobreposição amigável: max(), min(), gcd(), f(x, y) = x

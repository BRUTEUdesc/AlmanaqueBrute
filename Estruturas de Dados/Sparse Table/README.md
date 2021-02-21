### PT-BR

# Sparse Table
Responde consultas de maneira eficiente em um conjunto de dados estáticos.\
Realiza um pré-processamento para diminuir o tempo de cada consulta.
* Complexidade de tempo (Pré-processamento): O(N * log(N))
* Complexidade de tempo (Consulta para operações sem sobreposição amigável): O(N * log(N))
* Complexidade de tempo (Consulta para operações com sobreposição amigável): O(1)
* Complexidade de espaço: O(N * log(N))

Exemplo de operações com sobreposição amigável: max(), min(), gcd(), f(x, y) = x

### EN-US

# Sparse Table
Answers queries in an efficient way on a set of static data.\
Does a preprocessing to reduce the time of each query.
* Time complexity (Preprocessing): O(N * log(N))
* Time complexity (Query for non overlap friendly operations): O(N * log(N))
* Time complexity (Query for overlap friendly operations): O(1)
* Space complexity: O(N * log(N))

Example of overlap friendly operations: max(), min(), gcd(), f(x, y) = x

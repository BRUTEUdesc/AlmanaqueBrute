# [Custom Hash](custom_hash.cpp)

As funções de hash padrão do `unordered_map` e `unordered_set` são muito propícias a colisões (principalmente se o setter da questão criar casos de teste pensando nisso).
Para evitar isso, é possível criar uma função de hash customizada.

Entretanto, é bem raro ser necessário usar isso. Geralmente o fator $\mathcal{O}(\log n)$ de um `map` é suficiente.

Exemplo de uso: `unordered_map<int, int, custom_hash> mp;`
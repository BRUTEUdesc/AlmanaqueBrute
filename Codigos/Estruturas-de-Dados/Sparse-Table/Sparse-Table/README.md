# [Sparse Table](sparse_table.cpp)

Precomputa em $\mathcal{O}(n \log n)$ uma tabela que permite responder consultas de mínimo/máximo em intervalos em $\mathcal{O}(1)$.

A implementação atual é para mínimo, mas pode ser facilmente modificada para máximo ou outras operações.

A restrição é de que a operação deve ser associativa e idempotente (ou seja, $f(x, x) = x$).

Exemplos de operações idempotentes: `min`, `max`, `gcd`, `lcm`.

Exemplos de operações não idempotentes: `soma`, `xor`, `produto`.

**Obs**: não suporta updates.

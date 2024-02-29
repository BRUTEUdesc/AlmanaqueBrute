# [Random em C++](rand.cpp)

É possível usar a função `rand()` para gerar números aleatórios em `C++`.
Útil para gerar casos aleatórios em stress test, porém não é recomendado para usar em soluções.
`rand()` gera números entre `0` e `RAND_MAX` (que é pelo menos `32767`), mas costuma ser `2147483647` (depende do sistema/arquitetura).
Para usar o `rand()`, recomenda-se no mínimo chamar a função `srand(time(0))` no início da `main()` para inicializar a seed do gerador de números aleatórios.

Para usar números aleatórios em soluções, recomenda-se o uso do `mt19937` que está no código abaixo.
A função `rng()` gera números entre `0` e `UINT_MAX` (que é `4294967295`).
Para gerar números aleatórios de 64 bits, usar `mt19937_64` como tipo do `rng`.
Recomenda-se o uso da função `uniform(l, r)` para gerar números aleatórios no intervalo fechado $[l, r]$ usando o `mt19937`.

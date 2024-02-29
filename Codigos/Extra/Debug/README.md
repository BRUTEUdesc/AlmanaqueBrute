# [Debug](debug.cpp)

Template para debugar variáveis em `C++`. Até a linha 17 é opcional, é pra permitir que seja possível debugar `std::pair` e `std::vector`.
Para usar, basta compilar com a flag `-DBRUTE` (o template `run` já tem essa flag). E no código usar `debug(x, y, z)` para debugar as variáveis `x`, `y` e `z`.
# Máximo divisor comum

Algoritmo Euclides para computar o Máximo Divisor Comum (MDC em português; GCD em inglês), e variações.

*Read in [English](README.en.md)*

# [Algoritmo de Euclides](gcd.cpp)

Computa o Máximo Divisor Comum (MDC em português; GCD em inglês).

- Complexidade de tempo: $\mathcal{O}(\log n)$

Mais demorado que usar a função do compilador C++ `__gcd(a,b)`.

# [Algoritmo de Euclides Estendido](extended_gcd.cpp)

Algoritmo extendido de euclides que computa o Máximo Divisor Comum e os valores x e y tal que a * x + b * y = gcd(a, b).

- Complexidade de tempo: $\mathcal{O}(\log n)$

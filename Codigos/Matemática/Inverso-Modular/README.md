# Inverso Modular

Algoritmos para calcular o inverso modular de um número. O inverso modular de um inteiro $a$ é outro inteiro $x$ tal que $a \cdot x \equiv 1 \pmod{MOD}$

O inverso modular de um inteiro $a$ é outro inteiro $x$ tal que $a * x$ é congruente a $1 \mod MOD$.

# [Inverso Modular](modular_inverse.cpp)

Calcula o inverso modular de $a$.

Utiliza o algoritmo Exp Mod, portanto, espera-se que $MOD$ seja um número primo.

* Complexidade de tempo: $\mathcal{O}(\log(\text{MOD}))$.
* Complexidade de espaço: $\mathcal{O}(1)$.

# [Inverso Modular por MDC Estendido](modular_inverse_coprime.cpp)

Calcula o inverso modular de $a$.

Utiliza o algoritmo Euclides Extendido, portanto, espera-se que $MOD$ seja coprimo com $a$.

Retorna $-1$ se essa suposição for quebrada.

* Complexidade de tempo: $\mathcal{O}(\log(\text{MOD}))$.
* Complexidade de espaço: $\mathcal{O}(1)$.

# [Inverso Modular para 1 até MAX](modular_inverse_linear.cpp)

Calcula o inverso modular para todos os números entre $1$ e $MAX$.

Espera-se que $MOD$ seja primo.

* Complexidade de tempo: $\mathcal{O}(\text{MAX})$.
* Complexidade de espaço: $\mathcal{O}(\text{MAX})$.

# [Inverso Modular para todas as potências](modular_inverse_pow.cpp)

Seja $b$ um número inteiro qualquer.

Calcula o inverso modular para todas as potências de $b$ entre $b^0$ e $b^MAX$.

É necessário calcular antecipadamente o inverso modular de $b$, para 2 é sempre $(MOD+1)/2$.

Espera-se que $MOD$ seja coprimo com $b$.

* Complexidade de tempo: $\mathcal{O}(\text{MAX})$.
* Complexidade de espaço: $\mathcal{O}(\text{MAX})$.
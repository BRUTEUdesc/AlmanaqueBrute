# [Modular Int](mint.cpp)

O Mint é uma classe que representa um número inteiro módulo um **número primo**. Ela é útil para evitar overflow em operações de multiplicação e exponenciação, e também para facilitar a implementações.

Propriedades básicas de aritmética modular:
- $(a + b) \space \text{mod} \space m \equiv (a \space \text{mod} \space m + b \space \text{mod} \space m) \space \text{mod} \space m$
- $(a - b) \mod m \equiv (a \mod m - b \mod m) \mod m$
- $(a \cdot b) \mod m \equiv (a \mod m \cdot b \mod m) \mod m$
- $a^b \mod m \equiv (a \mod m)^b \mod m$
- Adicionalmente, $a^b \mod m \equiv (a \mod m)^{b \mod \phi(m)} \mod m$, onde $\phi(m)$ é a função totiente de Euler.

Divisões funcionam um pouco diferente, para realizar $a/b$ deve-se fazer $a \cdot b^{-1}$, onde $b^{-1}$ é o **inverso multiplicativo** de $b$ módulo $m$, tal que $b \cdot b^{-1} \equiv 1 \mod m$. No código, basta usar o operador de divisão normal pois a classe já está implementada com o inverso multiplicativo.

Para usar o Mint, basta declarar o tipo e usar como se fosse um inteiro normal. Exemplo:

```cpp
const int MOD = 7; // MOD = 7 para fins de exemplo
using mint = Mint<MOD>;
mint a = 4, b = 3;
mint c = a * b; // c == 5
mint d = 1 / a; // d == 2
mint e = a * d // e == 1
a = a + 2; // a == 6
a = a + 3; // a == 2
a = a ^ 5; // a == 4
a = a - 6; // a == 5
```

# [Modular Int](mint.cpp)

O Mint é uma classe que representa um número inteiro módulo número inteiro $\text{MOD}$. Ela é útil para evitar overflow em operações de multiplicação e exponenciação, e também para facilitar implementações.

Ao usar o Mint, você deve passar os valores para ele **já modulados**, ou seja, valores entre $-\text{MOD}$ e $\text{MOD}-1$. O próprio Mint normaliza depois para ficar entre $0$ e $\text{MOD}-1$.

Para lembrar as propriedades de aritmética modular, consulte a seção Teórico desse Almanaque.

Para usar o Mint, basta criar um tipo com o valor de $\text{MOD}$ desejado. O valor de $\text{MOD}$ deve ser um número inteiro positivo, podendo ser tanto do tipo `int` quanto `long long`.

```cpp
using mint = Mint<7>;
// using mint = Mint<(ll)1e18 + 9> para long long
mint a = 4, b = 3;
mint c = a * b; // c.v == 5
mint d = 1 / a; // d.v == 2, MOD deve ser primo para usar o operador de divisão
mint e = a * d; // e.v == 1
a = a + 2; // a.v == 6
a = a + 3; // a.v == 2
a = a ^ 5; // a.v == 4
a = a - 6; // a.v == 5
```

**Obs**: para o operador de divisão, o Mint usa o inverso multiplicativo de $a$ baseado no Teorema de Euler (consulte o Teórico para mais detalhes), que é $a^{\text{MOD}-2}$. Portanto, o $\text{MOD}$ deve ser primo.

# [Hashing Dinâmico](dynamic_hashing.cpp)

Hashing polinomial para testar igualdade de strings (ou de vetores). Requer precomputar as potências de um primo, como indicado na função `precalc`. A implementação está com dois MODS e usa a primitiva `Mint`, a escolha de usar apenas um MOD ou não usar o `Mint` vai da sua preferência ou necessidade, se não usar o `Mint`, trate adequadamente as operações com aritmética modular.
Essa implementação suporta updates pontuais, utilizando-se de uma `Fenwick Tree` para isso. A construção é $\mathcal{O}(n)$, consultas e updates são $\mathcal{O}(\log n)$.

**Obs**: lembrar de chamar a função `precalc`!

Exemplo de uso:

```cpp  
string s = "abacabab";
DynamicHashing a(s);
cout << (a(0, 1) == a(2, 3)) << endl; // 0
cout << (a(0, 1) == a(4, 5)) << endl; // 1
a.update(0, 'c');
cout << (a(0, 1) == a(4, 5)) << endl; // 0
```

# [Hashing](hashing.cpp)

Hashing polinomial para testar igualdade de strings (ou de vetores). Requer precomputar as potências de um primo, como indicado na função `precalc`. A implementação está com dois MODS e usa a primitiva `Mint`, a escolha de usar apenas um MOD ou não usar o `Mint` vai da sua preferência ou necessidade, se não usar o `Mint`, trate adequadamente as operações com aritmética modular. A construção é $\mathcal{O}(n)$ e a consulta é $\mathcal{O}(1)$.

**Obs**: lembrar de chamar a função `precalc`!

Exemplo de uso:

```cpp
string s = "abacabab";
Hashing h(s);
cout << (h(0, 1) == h(2, 3)) << endl; // 0
cout << (h(0, 1) == h(4, 5)) << endl; // 1
cout << (h(0, 2) == h(4, 6)) << endl; // 1
cout << (h(0, 3) == h(4, 7)) << endl; // 0
cout << (h(0, 3) + h(4, n - 1) * pot[4] == h(0, n - 1)) << endl; // 1, da pra shiftar o hash
string t = "abacabab";
Hashing h2(t);
cout << (h() == h2()) << endl; // 1, pode comparar os hashes diretamente
```

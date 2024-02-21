# [Hashing](hashing.cpp)

Hashing polinomial para testar igualdade de strings (ou de vetores). Requer precomputar as potências de um primo, como indicado na função `precalc`. A implementação está com dois MODS e usa a primitiva `Mint`, pode-se alterar caso necessário. A construção é $\mathcal{O}(n)$ e a consulta é $\mathcal{O}(1)$.

Exemplo de uso:

```cpp  
string s = "abacabab";
Hashing a(s);
cout << (a(0, 1) == a(2, 3)) << endl; // 0
cout << (a(0, 1) == a(4, 5)) << endl; // 1
cout << (a(0, 2) == a(4, 6)) << endl; // 1
cout << (a(0, 3) == a(4, 7)) << endl; // 0
```

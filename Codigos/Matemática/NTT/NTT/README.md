# [NTT](ntt.cpp)

Computa a multiplicação de polinômios com coeficientes inteiros módulo um número primo em $\mathcal{O}(N \cdot \log N)$. Exatamente o mesmo algoritmo da FFT, mas com inteiros.

Não é qualquer módulo que funciona, aqui tem alguns que funcionam:

1. $998244353$ ($\approx 9 \times 10^8$): Para polinômios de tamanho até $2^{23}$.
2. $1004535809$ ($\approx 10^9$): Para polinômios de tamanho até $2^{21}$.
3. $1092616193$ ($\approx 10^9$): Para polinômios de tamanho até $2^{21}$.
4. $9223372036737335297$ ($\approx 9 \times 10^{18}$): Para polinômios de tamanho até $2^{24}$, se usar esse módulo, cuidado com os `ints`, use `long long`.

**Obs**: Essa implementação usa a primitiva `Mint` desse Almanaque. Se você não quiser usar o `Mint`, basta substituir todas as ocorrências de `Mint` por `int` ou `long long` e tratar adequadamente as operações com aritmética modular.

**Obs 2**: Nem tente usar $10^9 + 7$ ou $10^9 + 9$ como módulo, eles não funcionam. Para isso, pode-se tentar usar a NTT Big Modulo.
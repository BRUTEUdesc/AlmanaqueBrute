# [NTT Big Mod](big_ntt.cpp)

Computa a multiplicação de polinômios com coeficientes inteiros módulo um número primo em $\mathcal{O}(N \cdot \log N)$. Esse código usa do mesmo código da NTT padrão, com alguns ajustes especificados nos comentários do código.

Esse código está com módulo $9.223.372.036.737.335.297$ $(549.755.813.881 \cdot 2^{24} + 1)$ e aceita polinômios de tamanho até $2^{24}$ = $16.777.216$ $\approx 1.7 \times 10^7$.

**Obs**: Essa implementação usa a primitiva `Mint` desse Almanaque. Se você não quiser usar o `Mint`, basta substituir todas as ocorrências de `Mint` por `int` ou `long long` e tratar adequadamente as operações com aritmética modular.
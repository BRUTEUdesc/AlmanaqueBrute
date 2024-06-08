# [Numeric Theoric Transformation](ntt.cpp)

Computa a multiplicação de polinômios com coeficientes inteiros módulo um número primo em $\mathcal{O}(n \log n)$. Exatamente o mesmo algoritmo da FFT, mas com inteiros.

Esse código está com módulo 998244353 e aceita polinômios de tamanho até $2^{23}$ = $8.388.608$ $\approx 8 \times 10^6$.

Para se alterar o módulo ou o tamanho máximo do polinômio, basta alterar as constantes $\text{MOD}$ e encontrar uma raiz primitiva de ordem `MAXN` módulo $\text{MOD}$ (onde `MAXN` é uma potência de 2 e o tamanho máximo do polinômio).

Formalmente falando, uma raiz primitiva de ordem $n$ módulo $p$ é um inteiro $g$ tal que $g^n \equiv 1 \pmod{p}$ e $g^k \not\equiv 1 \pmod{p}$ para todo $0 < k < n$.

Algumas raízes conhecidas para alguns módulos:

TODO
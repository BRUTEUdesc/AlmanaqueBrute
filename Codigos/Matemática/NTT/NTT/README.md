# [Number Theoric Transform](ntt.cpp)

Computa a multiplicação de polinômios com coeficientes inteiros módulo um número primo em $\mathcal{O}(n \log n)$. Exatamente o mesmo algoritmo da FFT, mas com inteiros.

Esse código está com módulo $998.244.353$ $(119 \cdot 2^{23} + 1)$ e aceita polinômios de tamanho até $2^{23}$ = $8.388.608$ $\approx 8 \times 10^6$.

Para se alterar o módulo ou o tamanho máximo do polinômio, basta alterar as constantes `MOD`, `len_ntt` e encontrar uma raiz da unidade de ordem `len_ntt` módulo `MOD` (onde `len_ntt` é uma potência de 2 e o tamanho máximo do polinômio), no código, essa raiz é a variável `root_ntt`.

Formalmente, uma raiz da unidade de ordem $n$ módulo $p$ é um inteiro $g$ tal que $g^n \equiv 1 \pmod{p}$ e $g^k \not\equiv 1 \pmod{p}$ para todo $k$ tal que $0 < k < n$.

Algumas raízes conhecidas para alguns módulos e alguns tamanhos máximos de polinômios:

|           Módulo            |   Len    |       Raiz da Unidade       |
|-----------------------------|----------|-----------------------------|
|        $998.244.353$        | $2^{23}$ |          $102.292$          |
|       $1.004.535.809$       | $2^{21}$ |           $4.172$           |
|       $1.092.616.193$       | $2^{21}$ |            $155$            |
| $9.223.372.036.737.335.297$ | $2^{24}$ | $2.419.180.138.865.645.092$ |

Essa última raiz para esse módulo enorme está melhor descrita na seção NTT Big Mod.

**Obs**: Essa implementação usa a primitiva `Mint` desse Almanaque. Se você não quiser usar o `Mint`, basta substituir todas as ocorrências de `Mint` por `int` ou `long long` e tratar adequadamente as operações com aritmética modular.
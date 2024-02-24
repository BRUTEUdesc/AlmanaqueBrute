# [Autômato de KMP](aut_kmp.cpp)

O autômato de KMP computa em $\mathcal{O}(|s| \cdot \Sigma)$ a função de transição de uma string, que é definida por:

$$ nxt[i][c] = \max\{k: k \leq i \land s[0:k] = s[i-k:i-1]c\} $$

Em outras palavras, $nxt[i][c]$ é o tamanho do maior prefixo de $s$ que é sufixo de $s[0:i-1]c$.

O autômato de KMP é útil para mútiplos pattern matchings, ou seja, dado um padrão $t$, encontrar todas as ocorrências de $t$ em várias strings $s_1, s_2, \dots, s_k$, em $\mathcal{O}(|t| + \sum |s_i|)$. O método `matching` faz isso.

**Obs**: utiliza o código do KMP.
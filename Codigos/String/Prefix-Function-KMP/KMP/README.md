# [KMP](kmp.cpp)

O algoritmo de Knuth-Morris-Pratt (KMP) computa em $\mathcal{O}(|s|)$ a Prefix Function de uma string, cuja definição é dada por:

$$ p[i] = \max\{k \mid s[0,k) = s(i-k,i]\} $$

Em outras palavras, $p[i]$ é o tamanho do maior prefixo de $s$ que é sufixo próprio de $s[0,i]$.

O KMP é útil para pattern matching, ou seja, encontrar todas as ocorrências de uma string $t$ em uma string $s$, como faz a função `matching` em $O(|s| + |t|)$.
# [Z Function](z.cpp

O algoritmo abaixo computa o vetor Z de uma string, definido por:

$$ Z[i] = \max \{ k \geq 0 : s[0,k) = s[i,i+k) \} + 1 $$

É muito semelhante ao KMP em termos de aplicações. Usado principalmente para pattern matching.
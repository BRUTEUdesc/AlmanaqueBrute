# [Z Function](z.cpp)

O algoritmo abaixo computa o vetor Z de uma string, definido por:

$$ z[i] = \max\{k \mid s[0,k) = s[i,i+k)\} $$

Em outras palavras, $z[i]$ é o tamanho do maior prefixo de $s$ é prefixo de $s[i,|s|-1]$.

É muito semelhante ao KMP em termos de aplicações. Usado principalmente para pattern matching.
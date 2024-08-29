# [Suffix Array](suffix_array.cpp)

Estrutura que conterá inteiros que representam os índices iniciais de todos os sufixos ordenados de uma determinada string.

Também constrói a tabela LCP (Longest Common Prefix).

- `sa[i]` = Índice inicial do i-ésimo menor sufixo.
- `ra[i]` = Rank do sufixo que começa em `i`.
- `LCP[i]` = Comprimento do maior prefixo comum entre os sufixos `sa[i]` e `sa[i-1]`.

* Complexidade de tempo (Pré-Processamento): $\mathcal{O}(|S| \cdot \log(|S|))$
* Complexidade de tempo (Contar ocorrências de \(S\) em \(T\)): $\mathcal{O}(|S| \cdot \log(|T|))$

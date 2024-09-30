# [EertreE](eertree.cpp)

Constrói a Palindromic Tree de uma string $S$ em $\mathcal{O}(|S|)$. Todo nodo da árvore representa exatamente uma substring palindrômica de $S$.

- `len[u]` representa o tamanho do palíndromo representado pelo nodo `u`.
- `lnk[u]` é o nodo que representa o maior sufixo palindrômico do nodo `u`.
- `cnt[u]` é a frequência da substring representada pelo nodo `u`.
- `first[u]` representa a primeira ocorrência da substring representada pelo nodo `u`, note que `first[u]` guarda o índice do último caractere dessa substring.
- `number_of_palindromes()` retorna a quantidade de substrings palindrômicas de $S$, lembre-se de chamar a função `build_cnt()` antes dessa.
- `number_of_distinct_palindromes()` retorna a quantidade de substrings palindrômicas distintas.
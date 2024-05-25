# [Aho-Corasick](aho_corasick.cpp)

Muito parecido com uma Trie, porém muito mais poderoso. O autômato de Aho-Corasick é um autômato finito determinístico que pode ser construído a partir de um conjunto de padrões. Nesse autômato, para qualquer nodo $u$ do autômato e qualquer caractere $c$ do alfabeto, é possível transicionar de $u$ usando o caractere $c$.

A transição é feita por uma aresta direta de $u$ pra $v$, se a aresta de $u$ pra $v$ estiver marcada com o caractere $c$. Se não, a transição de $u$ com o caractere $c$ é a transição de $link(u)$ com o caractere $c$.

**Definição**: $link(u)$ é um nodo $v$, tal que o prefixo do autômato ate $v$ é sufixo de $u$, e esse prefixo é o maior possível. Ou seja, $link(u)$ é o maior prefixo do autômato que é sufixo de $u$. Com apenas um padrão inserido, o autômato de Aho-Corasick é a Prefix Function (KMP).

No código, `cur` é o próximo nodo a ser criado. A root é o nodo $1$.
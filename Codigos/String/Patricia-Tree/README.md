# [Patricia Tree ou Patricia Trie](patricia_tree.cpp)

Estrutura de dados que armazena strings e permite consultas por prefixo, muito similar a uma Trie.

Implementação PB-DS, extremamente curta e confusa:

Exemplo de uso:

```cpp
patricia_tree pat;
pat.insert("exemplo");
pat.erase("exemplo");
pat.find("exemplo") != pat.end(); // verifica existência
auto match = pat.prefix_range("ex"); // pega palavras que começam com "ex"
for (auto it = match.first; it != match.second; ++it); // percorre match
pat.lower_bound("ex"); // menor elemento lexicográfico maior ou igual a "ex"
pat.upper_bound("ex"); // menor elemento lexicográfico maior que "ex"
```

**TODAS AS OPERAÇÕES EM $\mathcal{O}(|S|)$**  
**NÃO ACEITA ELEMENTOS REPETIDOS**

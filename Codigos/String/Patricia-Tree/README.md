# [Patricia Tree ou Patricia Trie](patricia_tree.cpp)
Implementação PB-DS, extremamente curta e confusa:

- Criar: `patricia_tree pat;`
- Inserir: `pat.insert("sei la");`
- Remover: `pat.erase("sei la");`
- Verificar existência: `pat.find("sei la") != pat.end();`
- Pegar palavras que começam com um prefixo: `auto match = pat.prefix_range("sei");`
- Percorrer *match* : `for(auto it = match.first; it != match.second; ++it);`
- Pegar menor elemento lexicográfico *maior ou igual* ao prefixo: `*pat.lower_bound("sei");` 
- Pegar menor elemento lexicográfico *maior* ao prefixo: `*pat.upper_bound("sei");` 

**TODAS AS OPERAÇÕES EM O( |S| )**  
**NÃO ACEITA ELEMENTOS REPETIDOS**

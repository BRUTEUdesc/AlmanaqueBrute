# [Divide and Conquer](dc.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização para DP de prefixo quando se pretende separar o vetor em K subgrupos.    
É preciso fazer a função query(i, j) que computa o custo do subgrupo \[i, j\].
* Complexidade de tempo: O(n * k * log(n) *  O(query))

# [Divide and Conquer com Query on demand](dc_query_ondemand.cpp)

<!-- *Read in [English](README.en.md)* -->

Usado para evitar queries pesadas ou o custo de pré-processamento.  
É preciso fazer as funções da estrutura **janela**, eles adicionam e removem itens um a um como uma janela flutuante.

* Complexidade de tempo: O(n * k * log(n) * O(update da janela))



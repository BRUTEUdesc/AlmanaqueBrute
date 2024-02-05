# [Divide and Conquer](dc.cpp)

<!-- DESCRIPTION -->
Otimização para DP de prefixo quando se pretende separar o vetor em \(K\) subgrupos.    
<!-- DESCRIPTION -->

É preciso fazer a função query(i, j) que computa o custo do subgrupo \[i, j\].
* Complexidade de tempo: $\mathcal{O}(n \cdot k \cdot \log(n) \cdot  \mathcal{O}(\text{query}))$

# [Divide and Conquer com Query on demand](dc_query_ondemand.cpp)

Usado para evitar queries pesadas ou o custo de pré-processamento.  
É preciso fazer as funções da estrutura **janela**, eles adicionam e removem itens um a um como uma janela flutuante.

* Complexidade de tempo: $\mathcal{O}(n \cdot k \cdot \log(n) \cdot \mathcal{O}(\text{update da janela}))$
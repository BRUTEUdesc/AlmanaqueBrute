# [Divide and Conquer](dc.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização de DP para aquelas do tipo de separar um vetor de N objetos em K subgrupos de modo a maximizar ou minizar a soma do custos dos grupos.   
É preciso fazer a função query(i, j) que computa o custo do subgrupo \[i, j\].
* Complexidade de tempo: O(n * k * log(n) *  O(query))


# [Divide and Conquer com Query on demand](dc_query_ondemand.cpp)

<!-- *Read in [English](README.en.md)* -->

O mesmo que Divide and Conquer, porém mais comprido.   
Usado para evitar queries pesadas ou o custo de pré-processamento.  
É preciso fazer as funções da estrutura **range**, eles adicionam e removem itens um a um como uma janela flutuante.

* Complexidade de tempo: O(n * k * log(n) * O(update do range))



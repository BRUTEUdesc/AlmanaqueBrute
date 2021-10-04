# [Divide and Conquer](dc.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização de DP para aquelas do tipo de separar um vetor de N objetos em K subgrupos de modo a maximizar ou minizar a soma do custos dos grupos.

* Complexidade de tempo: O(n * k * log(n))

É preciso fazer a função query(i, j) que computa o custo do subgrupo \[i, j\];

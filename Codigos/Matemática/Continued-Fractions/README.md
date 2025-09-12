# [Frações Contínuas](continued_fractions.cpp)
 Inspirado pelo artigo no CP Algorithms: https://cp-algorithms.com/algebra/continued-fractions.html

 Computa fração continua a partir de fração racional e vice-versa.  
 `lca(u, v)` computa o lca das frações `u` e `v` na Stern-Brocott Tree

 Tamanho da fração contínua e complexidade para computá-la a partir da fração racional A/B: \mathcal{O}(\log (A + B)). 
 Portanto, lca e outros métodos têm mesma complexidade. 

 Testado apenas em: https://atcoder.jp/contests/abc408/tasks/abc408_g  

 IMPORTANTE: Cuidado com "inf" quando usando "plus_minus_eps" - chamar "convergents" para uma fração contínua 
 com "inf" no final restulta em overflow. 

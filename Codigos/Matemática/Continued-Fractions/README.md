# [Frações Contínuas](continued_fractions.cpp)
 Inspirado pelo artigo no CP Algorithms: https://cp-algorithms.com/algebra/continued-fractions.html

 Computa fração continua a partir de fração racional e vice-versa
 lca(u, v) computa o lca das frações u e v na Stern-Brocott Tree

 Testado apenas em: https://atcoder.jp/contests/abc408/tasks/abc408_g (example 1) 

 Notes: CAREFUL WITH "inf" WHEN WORKING WITH "plus_minus_eps"
     CALLING "convergents" TO A CONTINUED FRACTION WITH "inf" IN THE END WILL MAKE IT OVERFLOW 

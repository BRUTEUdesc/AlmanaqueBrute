# [NTT Big Mod](big_ntt.cpp)

NTT usada para computar a multiplicação de polinômios com coeficientes inteiros módulo um número primo grande. A ideia na maioria dos casos é computar a multiplicação como se não houvesse módulo, por isso usamos um módulo grande.

Uma forma de fazer essa NTT com módulo grande é usar o módulo grande que está na seção NTT.

A forma usada nesse código é usar dois módulos na ordem de $10^9$ e fazer a multiplicação com eles. E depois usar o Teorema do Resto Chinês para achar o resultado módulo o produto dos módulos.
# [Operation Queue](op_queue.cpp)

Fila que armazena o resultado do operatório dos itens (ou seja, dado uma fila, responde qual é o elemento mínimo, por exemplo). É uma extensão da $std::queue$ que permite as operações $push$, $pop$, $front$ e $back$ em $O(1)$ amortizado, agora permitindo também a operação $get$ que retorna o resultado do operatório dos itens da fila em $O(1)$ amortizado.

Obs: usa a estrutura Operation Stack.

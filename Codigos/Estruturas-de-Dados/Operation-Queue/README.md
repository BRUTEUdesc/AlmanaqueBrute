# [Operation Queue](op_queue.cpp)

Fila que armazena o resultado do operatório dos itens (ou seja, dado uma fila, responde qual é o elemento mínimo, por exemplo). É uma extensão da $std::queue$, permitindo todos os métodos já presentes nela, com a diferença de que $push$ e $pop$ agora são $add$ e $remove$, respectivamente, ambos continuam $\mathcal{O}(1)$ amortizado. A fila agora também permite a operação $get$ que retorna o resultado do operatório dos itens da fila em $\mathcal{O}(1)$ amortizado. Chamar o método $get$ em uma fila vazia é indefinido.

**Obs**: usa a estrutura Operation Stack.

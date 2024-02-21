# [Operation Stack](op_stack.cpp)

Pilha que armazena o resultado do operatório dos itens (ou seja, dado uma pilha, responde qual é o elemento mínimo, por exemplo). É uma extensão da `std::stack`, permitindo todos os métodos já presentes nela, com a diferença de que `push` e `pop` agora são `add` e `remove`, respectivamente, ambos continuam $\mathcal{O}(1)$ amortizado. A pilha agora também permite a operação `get` que retorna o resultado do operatório dos itens da pilha em $\mathcal{O}(1)$ amortizado. Chamar o método `get` em uma pilha vazia é indefinido.

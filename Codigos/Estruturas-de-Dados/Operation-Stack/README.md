# [Operation Stack](op_stack.cpp)

Pilha que armazena o resultado do operatório dos itens (ou seja, dado uma pilha, responde qual é o elemento mínimo, por exemplo). A pilha possui a operação `get` que retorna o resultado do operatório dos itens da pilha em $\mathcal{O}(1)$ amortizado. Chamar o método `get` em uma pilha vazia é indefinido.

A pilha é um template e recebe como argumentos o tipo dos itens e a função operatória. A função operatória deve receber dois argumentos do tipo dos itens e retornar um valor do mesmo tipo.

Exemplo de como passar a função operatória para a pilha:
    
```cpp
int f(int a, int b) { return a + b; }

void test() {
    auto g = [](int a, int b) { return a ^ b; };

    op_stack<int, f> st;
    op_stack<int, g> st2;

    st.push(1);
    st.push(1);
    st2.push(1);
    st2.push(1);
    cout << st.get() << endl;
    cout << st2.get() << endl;
}
```

Pode ser tanto função normal quanto lambda.
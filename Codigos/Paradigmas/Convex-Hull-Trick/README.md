# Convex Hull Trick

Otimização de DP onde se mantém as retas que formam um Convex Hull em uma estrutura que permite consultar qual o melhor valor para um determinado $x$.

Só funciona quando as retas são monotônicas. Caso não sejam, usar LiChao Tree para guardar as retas.

Complexidade de tempo:

- Inserir reta: $\mathcal{O}(1)$ amortizado
- Consultar $x$: $\mathcal{O}(\log(N))$
- Consultar $x$ quando $x$ tem crescimento monotônico: $\mathcal{O}(1)$

A implementação mantém o **máximo** e exige que as retas sejam inseridas com coeficiente angular não-decrescente. Para o mínimo, insira $(-a, -b)$ e negue a resposta.

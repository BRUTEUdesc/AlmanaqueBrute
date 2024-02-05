# [KD Fenwick Tree](kd_fenwick_tree.cpp)

Fenwick Tree em $k$ dimensões. Faz apenas queries de prefixo e updates pontuais em $\mathcal{O}(log^k(n))$. Para queries em range, deve-se fazer inclusão-exclusão, porém a complexidade fica exponencial, para $k$ dimensões a query em range é $\mathcal{O}(2^k log^k(n))$.

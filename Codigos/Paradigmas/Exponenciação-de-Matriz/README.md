# [Exponenciação de Matriz](matrix_exp.cpp)

<!-- DESCRIPTION -->
Otimização para DP de prefixo quando o valor atual está em função dos últimos $K$ valores já calculados.   
<!-- DESCRIPTION -->

* Complexidade de tempo: $\mathcal{O}(log(n)*k^3)$

É preciso mapear a DP para uma exponenciação de matriz.

### Uso Comum

DP:   

$$ dp[n] = \sum_{i=1}^{k} c[i] \cdot dp[n - i] $$ 

Mapeamento:   

$$ \begin{pmatrix} 0&1&0&0&...&0 \\\ 0&0&1&0&...&0 \\\ 0&0&0&1&...&0 \\\ ...&...&...&...&...&... \\\ c[k]&c[k-1]&c[k-2]&...&c[1]&0 \end{pmatrix}^n \times \begin{pmatrix} dp[0] \\\ dp[1] \\\ dp[2] \\\ ... \\\ dp[k-1] \end{pmatrix} $$

---
### Variação que dependa de **constantes** e do **índice**

Exemplo de DP:   

$$ dp[i] = dp[i-1] + 2 \cdot i^2 + 3 \cdot i + 5 $$

Nesses casos é preciso fazer uma linha para manter cada constante e potência do índice.

Mapeamento:

$$ \begin{pmatrix} 1&5&3&2 \\\ 0&1&0&0 \\\ 0&1&1&0 \\\ 0&1&2&1 \end{pmatrix}^n \times \begin{pmatrix} dp[0]   \\\ 1       \\\ 1       \\\ 1\end {pmatrix} \begin{matrix} \text{mantém } dp[i]   \\\ \text{mantém }1       \\\ \text{mantém }i       \\\ \text{mantém }i^2      \end {matrix} $$

### Variação Multiplicativa

Exemplo de DP:

$$ dp[n] =  c\times \prod_{i=1}^{k} dp[n-i] $$

Nesses casos é preciso trabalhar com o logaritmo e temos o caso padrão:


$$ \log(dp[n]) =  log(c) + \sum_{i=1}^{k} log(dp[n-i]) $$

Se a resposta precisar ser inteira, deve-se fatorar a constante e os valores inicias e então fazer uma exponenciação para cada fator primo. Depois é só juntar a resposta no final.

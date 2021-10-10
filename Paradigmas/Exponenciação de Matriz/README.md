# [Exponenciação de Matriz](matrix_exp.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização para DP de prefixo quando o valor atual está em função dos últimos $K$ valores já calculados.   
* Complexidade de tempo: $O(log(n)\times k³)$

É preciso mapear a DP para uma exponenciação de matriz.

---


## Uso Comum

DP:   
![image](https://bit.ly/3uYCDuM)

Mapeamento:
$$
\begin{pmatrix}
    0 & 1 & 0 & 0 & . & . \\
    0 & 0 & 1 & 0 & . & . \\
    0 & 0 & 0 & 1 & . & . \\
    . & . & . & . & . & . \\
    c_k & c_{k-1} & c_{k — 2} & . & . & c_1
\end{pmatrix}^n
\times
\begin{pmatrix} 
    dp[0] \\
    dp[1] \\
    dp[2] \\
    \vdots \\
    dp[k — 1] \end
{pmatrix}
$$
---
## Variação que dependa de **constantes** e do **índice**

Exemplo de DP:
$$dp[i] = dp[i - 1] + 2 * i^2 + 3 * i + 5$$

Nesses casos é preciso fazer uma linha para manter cada constante e potência do índice.

Mapeamento:
$$
\begin{pmatrix} 1&5&3&2 \\ 0&1&0&0 \\ 0&1&1&0 \\ 0&1&2&1 \end{pmatrix}^n
\times
\begin{pmatrix} 
    dp[0]   \\
    1       \\
    1       \\
    1\end
{pmatrix} 
\begin{matrix} 
    mantém\ dp[i]   \\
    mantém\ 1       \\
    mantém\ i       \\
    mantém\ i²      \end
{matrix}
$$

---
## Variação Multiplicativa

DP:
$$dp[n] =  c\times \prod_{n=1}^{k} dp[n-k]$$

Nesses casos é preciso trabalhar com o logarítmo e temos o caso padrão:
$$\log(dp[n]) =  log(c) + \sum_{n=1}^{k} log(dp[n-k])$$


Se a resposta precisar ser inteira, deve-se fatorar a constante e os valores inicias e então fazer uma exponenciação para cada fator primo. Depois é só juntar a resposta no final.

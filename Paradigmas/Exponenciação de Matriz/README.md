# [Exponenciação de Matriz](matrix_exp.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização para DP de prefixo quando o valor atual está em função dos últimos ***K*** valores já calculados.   
* Complexidade de tempo: O(log(n) * k³)

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
![image](https://bit.ly/3Au4cNG)

Nesses casos é preciso fazer uma linha para manter cada constante e potência do índice.

Mapeamento:   
![image](https://bit.ly/3mDEKk1)

---
## Variação Multiplicativa

DP:   
![image](https://bit.ly/30fMnFN)

Nesses casos é preciso trabalhar com o logarítmo e temos o caso padrão:   
![image](https://bit.ly/3v0Yimj)

Se a resposta precisar ser inteira, deve-se fatorar a constante e os valores inicias e então fazer uma exponenciação para cada fator primo. Depois é só juntar a resposta no final.

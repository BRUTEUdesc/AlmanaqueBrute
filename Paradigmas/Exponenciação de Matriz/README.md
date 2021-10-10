# [Exponenciação de Matriz](matrix_exp.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização para DP de prefixo quando o valor atual está em função dos últimos $K$ valores já calculados.   
* Complexidade de tempo: O(log(n) k³)


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
![equation](http://www.sciweavers.org/tex2img.php?eq=dp%5Bi%5D+%3D+dp%5Bi+-+1%5D+%2B+2+%2A+i%5E2+%2B+3+%2A+i+%2B+5&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)
<!-- $$dp[i] = dp[i - 1] + 2 * i^2 + 3 * i + 5$$ -->
Nesses casos é preciso fazer uma linha para manter cada constante e potência do índice.

Mapeamento:
<!-- $$
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
$$ -->
![equation](http://www.sciweavers.org/tex2img.php?eq=%5Cbegin%7Bpmatrix%7D+1%265%263%262+%5C%5C+0%261%260%260+%5C%5C+0%261%261%260+%5C%5C+0%261%262%261+%5Cend%7Bpmatrix%7D%5En%0D%0A%5Ctimes%0D%0A%5Cbegin%7Bpmatrix%7D+%0D%0A++++dp%5B0%5D+++%5C%5C%0D%0A++++1+++++++%5C%5C%0D%0A++++1+++++++%5C%5C%0D%0A++++1%5Cend%0D%0A%7Bpmatrix%7D+%0D%0A%5Cbegin%7Bmatrix%7D+%0D%0A++++mant%C3%A9m%5C+dp%5Bi%5D+++%5C%5C%0D%0A++++mant%C3%A9m%5C+1+++++++%5C%5C%0D%0A++++mant%C3%A9m%5C+i+++++++%5C%5C%0D%0A++++mant%C3%A9m%5C+i%C2%B2++++++%5Cend%0D%0A%7Bmatrix%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)

---
## Variação Multiplicativa

DP:

![equation](http://www.sciweavers.org/tex2img.php?eq=dp%5Bn%5D+%3D++c%5Ctimes+%5Cprod_%7Bn%3D1%7D%5E%7Bk%7D+dp%5Bn-k%5D5&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)
<!-- $$dp[n] =  c\times \prod_{n=1}^{k} dp[n-k]$$ -->

Nesses casos é preciso trabalhar com o logarítmo e temos o caso padrão:
![equation](http://www.sciweavers.org/tex2img.php?eq=%5Clog%28dp%5Bn%5D%29+%3D++log%28c%29+%2B+%5Csum_%7Bn%3D1%7D%5E%7Bk%7D+log%28dp%5Bn-k%5D%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)

<!-- $$\log(dp[n]) =  log(c) + \sum_{n=1}^{k} log(dp[n-k])$$ -->


Se a resposta precisar ser inteira, deve-se fatorar a constante e os valores inicias e então fazer uma exponenciação para cada fator primo. Depois é só juntar a resposta no final.

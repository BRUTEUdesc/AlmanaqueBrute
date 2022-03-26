# [Exponenciação de Matriz](matrix_exp.cpp)

<!-- *Read in [English](README.en.md)* -->

Otimização para DP de prefixo quando o valor atual está em função dos últimos $K$ valores já calculados.   
* Complexidade de tempo: O(log(n) k³)


É preciso mapear a DP para uma exponenciação de matriz.

---


## Uso Comum

DP:   
```
          k               
         ___              
         ╲                
dp[n] =  ╱    c[k] ⋅ dp[n - k]
         ‾‾‾              
        n = 1                    
```

<!-- $$dp[n] = \sum_{n=1}^{k} c_{k} * dp[n-k]$$ -->


Mapeamento:   
```
                                                  n              
⎛  0      1       0        0       0    .    .   ⎞    ⎛ dp[0] ⎞
⎜                                                ⎟    ⎜       ⎟
⎜  0      0       1        0       0    .    .   ⎟    ⎜ dp[1] ⎟
⎜                                                ⎟    ⎜       ⎟
⎜  0      0       0        1       0    .    .   ⎟  ⋅ ⎜ dp[2] ⎟
⎜                                                ⎟    ⎜       ⎟
⎜  .      .       .        .       .    .    .   ⎟    ⎜   .   ⎟
⎜                                                ⎟    ⎜       ⎟
⎝ c[k] c[k-1]   c[k-2]   c[k-3]    .    .   c[1] ⎠    ⎝dp[k-1]⎠
```

---
## Variação que dependa de **constantes** e do **índice**

Exemplo de DP:   
```
dp[i] = dp[i-1] + 2i² + 3i + 5
```
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
```
                      n
⎛  1    5    3    2  ⎞     ⎛dp[0]⎞  mantém dp[i]
⎜                    ⎟     ⎜     ⎟
⎜  0    1    0    0  ⎟     ⎜  1  ⎟  mantém 1
⎜                    ⎟  .  ⎜     ⎟
⎜  0    1    1    0  ⎟     ⎜  1  ⎟  mantém i
⎜                    ⎟     ⎜     ⎟
⎝  0    1    2    1  ⎠     ⎝  1  ⎠  mantém i²
```

---
## Variação Multiplicativa

DP:
```
              k            
            ━┳━┳━           
dp[n] = c *  ┃ ┃   dp[n-k]
            n = 1          
```
<!-- $$dp[n] =  c\times \prod_{n=1}^{k} dp[n-k]$$ -->

Nesses casos é preciso trabalhar com o logarítmo e temos o caso padrão:


<!-- $$\log(dp[n]) =  log(c) + \sum_{n=1}^{k} log(dp[n-k])$$ -->
```
                        k                 
                       ___                
                       ╲                  
log(dp[n]) = log(c) +  ╱    log(dp[n-k])
                       ‾‾‾                
                      n = 1               
```

Se a resposta precisar ser inteira, deve-se fatorar a constante e os valores inicias e então fazer uma exponenciação para cada fator primo. Depois é só juntar a resposta no final.

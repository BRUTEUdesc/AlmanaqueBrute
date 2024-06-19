# [Pollard Rho](pollard_rho.cpp)

Algoritmo de Pollard Rho. A função `PollardRho::rho(X)` retorna um fator não trivial de $X$. Um fator não trivial é um fator que não é $1$ nem $X$. A complexidade esperada do algoritmo no pior caso é $\mathcal{O}(\sqrt[4]{X})$ (geralmente é mais rápido que isso).

**Obs**: cuidado para não passar um número primo ou o número $1$ para a função `rho`, o comportamente é indefinido (provavelmente entra em loop e não retorna nunca).

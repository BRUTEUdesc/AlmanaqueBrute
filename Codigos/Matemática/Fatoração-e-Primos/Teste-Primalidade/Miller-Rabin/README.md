# [Miller-Rabin](miller_rabin.cpp)

Teste de primalidade Miller-Rabin. A função `MillerRabin::prime(X)` retorna verdadeiro se $X$ é primo e falso caso contrário. O teste é determinístico para para números até $2^{64}$. A complexixade do algoritmo é $\mathcal{O}(\log X)$, considerando multiplicação e exponenciação constantes.

Para números até $2^{32}$, é suficiente usar `primes[] = {2, 3, 5, 7}`.
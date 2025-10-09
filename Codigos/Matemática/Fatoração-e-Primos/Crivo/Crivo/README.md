# [Crivo de Eratóstenes](sieve.cpp)

Crivo de Eratóstenes para encontrar os primos até um limite $P$. O `vector<bool> is_prime` é um vetor que diz se um número é primo ou não. A complexidade é $\mathcal{O}(P \log (\log P))$.

**Observações**:

- Para aplicações mais complexas ou para fatorar um número, consulte o Crivo Linear.
- Não se esqueça de chamar `Sieve::build()` antes de usar.

# [XOR Gauss](xor_gauss.cpp)

Mantém uma base num espaço vetorial de $L$ dimensões sobre $\mathbb{Z}_2$. Permite adicionar um vetor $v$ à base em $\mathcal{O}(L)$ e verificar se um vetor $v$ é representável pela base em $\mathcal{O}(L)$.

Em termos mais simples, dados $n$ inteiros, podemos adicionar cada um deles à base e isso nos dará uma base que consegue representar todos os XORs possíveis entre esses inteiros.

Também acha o k-ésimo menor vetor representável pela base em $\mathcal{O}(L)$, ou o k-ésimo maior vetor representável pela base em $\mathcal{O}(L)$.

Informações relevantes:

- $\text{rank}$ de uma base é o número de vetores que ela contém. No código é a variável `R`.
- Uma base consegue criar $2^{\text{rank}}$ vetores diferentes, ou seja, se criarmos uma base com base em um vetor de tamanho $n$, dentre todos os $2^n$ subsets possíveis, existem exatamente $2^{\text{rank}}$ XORs diferentes.
- Se uma base for criada a partir de um vetor de tamanho $n$, cada XOR possível feito por um subset desse vetor pode ser criado de exatamente $2^{n - \text{rank}}$ formas diferentes.

Os métodos são:

- `reduce`: recebe um número $x$ (será tratado como um vetor no espaço vetorial) e subtrai os vetores já existentes na base que estão presentes em $x$. Sendo assim, se ao final do `reduce`, $x$ for diferente de zero, ele não é representável por uma combinação linear dos vetores da base, se for zero, ele é representável.
- `insert`: insere um vetor na base, se ele não for representável. No caso, o vetor inserido ao tentar inserir um valor $x$ na base, será o `reduce` de $x$.
- `kth_greatest`: retorna o k-ésimo maior vetor representável pela base.
- `kth_smallest`: retorna o k-ésimo menor vetor não representável pela base.

Todos os métodos são $\mathcal{O}(L)$.
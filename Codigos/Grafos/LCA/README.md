# LCA (Lowest Common Ancestor)

Algoritmo para computar Lowest Common Ancestor usando EulerTour e Sparse Table (descrita na seção Estruturas de Dados), com pré-processamento em $\mathcal{O}(N \log N)$ e consulta em $\mathcal{O}(1)$.

No código, `st_lca` é uma Sparse Table idêntica a da seção de Estruturas de Dados, porém adaptada para guardar e retornar `pair<int, int>` ao invés de `long long`.

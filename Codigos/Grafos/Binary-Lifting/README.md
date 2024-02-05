# Binary Lifting

<!-- DESCRIPTION -->
Usa uma sparse table para calcular o k-ésimo ancestral de u.
<!-- DESCRIPTION -->

Pode ser usada com o algoritmo de EulerTour para calcular o LCA.

Complexidade de tempo:

- Pré-processamento: $\mathcal{O}(N * log(N))$
- Consulta do k-ésimo ancestral de u: $\mathcal{O}(log(N))$
- LCA: $\mathcal{O}(log(N))$

Complexidade de espaço: $\mathcal{O}(Nlog(N))$

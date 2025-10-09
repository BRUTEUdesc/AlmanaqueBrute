# Fluxo

Conjunto de algoritmos para calcular o fluxo máximo em redes de fluxo.

## Dinic

Adequado para grafos densos ou bipartidos. O grafo é armazenado internamente e as arestas devem ser adicionadas com `add_edge`.

- Complexidade de tempo: $\mathcal{O}(V^2 \cdot E)$; em grafos bipartidos, $\mathcal{O}(\sqrt{V} \cdot E)$.

A chamada `max_flow` altera o grafo adicionando o maior fluxo possível e retorna o valor desse fluxo máximo.

O corte mínimo de um grafo é equivalente ao fluxo máximo. Após `max_flow`, use `min_cut` para obter as arestas que compõem o corte mínimo.

## Edmonds-Karp

Indicado para grafos com poucas arestas.

- Complexidade de tempo: $\mathcal{O}(V \cdot E^2)$.

## Min Cost Max Flow

Calcula o fluxo máximo com custo mínimo.

- Complexidade de tempo: $\mathcal{O}(V^2 \cdot E^2)$.

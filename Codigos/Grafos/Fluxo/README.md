# Fluxo

<!-- DESCRIPTION -->
Conjunto de algoritmos para calcular o fluxo máximo em redes de fluxo.
<!-- DESCRIPTION -->

## Dinic

Muito útil para grafos bipartidos e para grafos com muitas arestas

Complexidade de tempo: $\mathcal{O}(V² * E)$, mas em grafo bipartido a complexidade é $\mathcal{O}(sqrt(V) * E)$

Guarda o grafo internamente, as arestas devem ser adicionadas pela função `add_edge`.

A função `max_flow` modifica o grafo adicionando a maior quantidade de fluxo possivel e retona a quantidade de fluxo adicionado.

O corte minimo de um grafo é equivalente ao fluxo máximo.
A Função `min_cut` acha as arestas pertencentes ao corte minimo do grafo, deve ser chamado após a função `max_flow`

## Edmonds Karp

Útil para grafos com poucas arestas

Complexidade de tempo: $\mathcal{O}(V * E²)$

## Min Cost Max Flow

Computa o fluxo máximo com custo mínimo

Complexidade de tempo: $\mathcal{O}(V² * E²)$

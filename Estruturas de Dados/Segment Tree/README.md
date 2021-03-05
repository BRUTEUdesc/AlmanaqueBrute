# Segment Tree

*Read in [English](README.en.md)*

# [Seg Tree](seg_tree.cpp)
Implementação padrão de Seg Tree
* Complexidade de tempo (Pré-processamento): O(N)
* Complexidade de tempo (Consulta em intervalo): O(log(N))
* Complexidade de tempo (Update em ponto): O(log(N))
* Complexidade de espaço: 4*N = O(N)

# [Seg Tree Lazy](seg_tree_lazy.cpp)
Implementação padrão de Seg Tree com lazy update
* Complexidade de tempo (Pré-processamento): O(N)
* Complexidade de tempo (Consulta em intervalo): O(log(N))
* Complexidade de tempo (Update em ponto): O(log(N))
* Complexidade de tempo (Update em intervalo): O(log(N))
* Complexidade de espaço: 2*4*N = O(N)

# [Seg Tree Beats](seg_tree_beats.cpp)
Seg Tree que suporta update de maximo e query de soma
* Complexidade de tempo (Pré-processamento): O(N)
* Complexidade de tempo (Consulta em intervalo): O(log(N))
* Complexidade de tempo (Update em ponto): O(log(N))
* Complexidade de tempo (Update em intervalo): O(log(N))
* Complexidade de espaço: 2*4*N = O(N)

# [Seg Tree Beats Max and Sum update](seg_tree_beats_max_and_sum_update.cpp)
Seg Tree que suporta update de maximo, update de soma e query de soma
Utiliza uma fila de lazy para diferenciar os updates
* Complexidade de tempo (Pré-processamento): O(N)
* Complexidade de tempo (Consulta em intervalo): O(log(N))
* Complexidade de tempo (Update em ponto): O(log(N))
* Complexidade de tempo (Update em intervalo): O(log(N))
* Complexidade de espaço: 2*4*N = O(N)

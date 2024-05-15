vector<tuple<int, int, int>> edges; // {u, v, w}

void kruskal(int n) {
    DSU dsu(n); // DSU da seção Estruturas de Dados

    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return get<2>(a) < get<2>(b);
    });

    for (auto [u, v, w] : edges) {
        if (dsu.unite(u, v)) {
            // edge u-v is in the MST
        }
    }
}

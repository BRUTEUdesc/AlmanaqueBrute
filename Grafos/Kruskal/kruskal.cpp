struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) { return w < other.w; }
};
typedef vector<Edge> ve;
typedef vector<int> vi;

ve edges, result;
vi parent, node_rank;
int cost;

void make_set(int u) {
    parent[u] = u;
    node_rank[u] = 0;
}

int find(int u) { return (u == parent[u] ? u : (parent[u] = find(parent[u]))); }

void union_set(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (node_rank[u] < node_rank[v]) swap(u, v);
        parent[v] = u;
        if (node_rank[u] == node_rank[v]) node_rank[u]++;
    }
}

void kruskal(int m, int n) {
    parent.resize(n);
    node_rank.resize(n);
    for (int i = 0; i < n; i++) make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cost += e.w;
            result.push_back(e);  // remove if only need cost
            union_set(e.u, e.v);
            if (result.size() == (m - 1)) break;
        }
    }
}
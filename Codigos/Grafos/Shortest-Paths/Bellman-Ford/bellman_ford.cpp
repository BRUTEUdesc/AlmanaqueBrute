const ll INF = 1e18;

int n;
vector<tuple<int, int, int>> edges;

vector<ll> bellman_ford(int s) {
    vector<ll> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges)
            if (dist[u] < INF) dist[v] = min(dist[v], dist[u] + w);
    }
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges)
            if (dist[u] < INF && dist[u] + w < dist[v]) dist[v] = -INF;
    }
    // dist[u] = -INF se tem um ciclo negativo que chega em u
    return dist;
}

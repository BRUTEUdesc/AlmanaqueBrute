const int MAX = 1e5 + 5, INF = 1e9 + 9;

vector<ii> adj[MAX];
int dist[MAX];

int dk(int s, int t) {
    priority_queue<ii, vector<ii>, greater<ii>> fila;
    fill(begin(dist), end(dist), INF);
    dist[s] = 0;
    fila.emplace(dist[s], s);
    while (!fila.empty()) {
        auto [d, u] = fila.top();
        fila.pop();
        if (u == t) {
            return dist[t];
        }
        if (d != dist[u]) {
            continue;
        }
        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                fila.emplace(dist[v], v);
            }
        }
    }
    return -1;
}

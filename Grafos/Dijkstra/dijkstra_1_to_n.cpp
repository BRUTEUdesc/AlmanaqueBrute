const int MAX = 2e5 + 5;
const ll INF = 1e18 + 18;

vector<ii> adj[MAX];
ll dist[MAX];

void dk(int s) {
    priority_queue<ii, vector<ii>, greater<>> fila;
    fill(begin(dist), end(dist), INF);
    dist[s] = 0;
    fila.emplace(dist[s], s);
    while (!fila.empty()) {
        auto [d, u] = fila.top();
        fila.pop();
        if (d != dist[u]) continue;
        for (auto [w, v]: adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                fila.emplace(dist[v], v);
            }
        }
    }
}

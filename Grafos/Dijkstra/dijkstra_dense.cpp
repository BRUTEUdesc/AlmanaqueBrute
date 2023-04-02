const ll MAX = 1e3 + 3;
const ll INF = 1e18 + 18;

ll adj[MAX][MAX], dist[MAX];

void dk(int s, int n) {
    fill(begin(dist), end(dist), INF);
    dist[s] = 0;
    vector<bool> vis(n);
    for (int it = 0; it < n; it++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        if (dist[u] == INF) break;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

const int MAX = 1e4 + 4;
const ll INF = 1e18 + 18;

vector<ii> adj[MAX];
ll dist[MAX];

void spfa(int s, int n) {
    fill(dist, dist + n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inq(n, false);
    queue<int> fila;
    fila.push(s);
    inq[s] = true;
    dist[s] = 0;
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        inq[u] = false;
        for (auto [w, v]: adj[u]) {
            ll newd = (dist[u] == -INF ? -INF : max(w + dist[u], -INF));
            if (newd < dist[v]) {
                dist[v] = newd;
                if (!inq[v]) {
                    fila.push(v);
                    inq[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n) { // negative cycle
                        dist[v] = -INF;
                    }
                }
            }
        }
    }
}

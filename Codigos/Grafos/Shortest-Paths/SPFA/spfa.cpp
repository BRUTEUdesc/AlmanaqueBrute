const int N = 1e4 + 5;
const ll INF = 1e18;

int n;
vector<pair<int, int>> adj[N];

vector<ll> spfa(int s) {
    vector<ll> dist(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(s);
    inq[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto [w, v] : adj[u]) {
            ll newd = (dist[u] == -INF ? -INF : max(w + dist[u], -INF));
            if (newd < dist[v]) {
                dist[v] = newd;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n) dist[v] = -INF; // negative cycle
                }
            }
        }
    }
    return dist;
}

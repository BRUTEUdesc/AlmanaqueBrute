const int N = 3e5 + 5;
const ll INF = 1e18;

int n;
vector<pair<int, int>> adj[N];

vector<ll> dijkstra(int s) {
    vector<ll> dist(n, INF);
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

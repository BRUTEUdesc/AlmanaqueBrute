const int N = 3e5 + 5;
const int INF = 1e9;

int n;
vector<pair<int, int>> adj[N];

vector<int> bfs01(int s) {
    vector<int> dist(n, INF);
    deque<int> q;
    dist[s] = 0;
    q.emplace_back(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    return dist;
}
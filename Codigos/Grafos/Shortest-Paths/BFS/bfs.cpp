const int N = 3e5 + 5;

int n;
vector<int> adj[N];

vector<int> bfs(int s) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.emplace(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }
    return dist;
}
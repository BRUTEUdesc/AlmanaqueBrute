namespace kosaraju {
    const int N = 1e5 + 5;
    int n, vis[N], root[N];
    vector<int> adj[N], inv[N], gc[N], topo;
    void add_edge(int u, int v) {
        adj[u].emplace_back(v);
        inv[v].emplace_back(u);
    }
    void toposort(int u) {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (vis[v]) continue;
            toposort(v);
        }
        topo.emplace_back(u);
    }
    void dfs(int u) {
        vis[u] = 1;
        for (auto v : inv[u]) {
            if (vis[v]) continue;
            root[v] = root[u];
            dfs(v);
        }
    }
    void solve(int n) {
        fill(vis, vis + n, 0);
        topo.clear();
        for (int i = 0; i < n; i++)
            if (!vis[i]) toposort(i);
        fill(vis, vis + n, 0);
        iota(root, root + n, 0);
        for (int i = n - 1; i >= 0; i--)
            if (!vis[topo[i]]) dfs(topo[i]);
        set<pair<int, int>> st;
        for (int u = 0; u < n; u++) {
            int ru = root[u];
            for (int v : adj[u]) {
                int rv = root[v];
                if (ru == rv) continue;
                if (!sete.count(ii(ru, rv))) {
                    gc[ru].emplace_back(rv);
                    sete.insert(ii(ru, rv));
                }
            }
        }
    }
}

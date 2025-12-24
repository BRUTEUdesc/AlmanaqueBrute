const int N = 3e5 + 5;
int n, m, timer, edge_id;
vector<pair<int, int>> adj[N]; // {to, edge id}
int tin[N], low[N];

void add_edge(int u, int v) {
    adj[u].push_back({v, edge_id});
    adj[v].push_back({u, edge_id});
    edge_id++;
}

void dfs_bridge(int u, int pe = -1) {
    low[u] = tin[u] = ++timer;
    for (auto [v, id] : adj[u]) {
        if (id == pe) continue;
        if (tin[v] != 0) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs_bridge(v, id);
            low[u] = min(low[u], low[v]);
        }
    }
    if (pe != -1 && low[u] == tin[u]) {
        // edge com id == pe (conectando p e u) eh ponte
    }
}

void find_bridges() {
    timer = edge_id = 0;
    for (int i = 0; i < n; i++) tin[i] = low[i] = 0;
    for (int i = 0; i < n; i++)
        if (tin[i] == 0) dfs_bridge(i);
}

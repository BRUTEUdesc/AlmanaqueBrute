const int N = 3e5 + 5;
int n, m, timer;
vector<int> adj[N];
int tin[N], low[N];

void dfs_bridge(int u, int p = -1) {
    low[u] = tin[u] = ++timer;
    for (int v : adj[u]) {
        if (tin[v] != 0 && v != p) {
            low[u] = min(low[u], tin[v]);
        } else if (v != p) {
            dfs_bridge(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (p != -1 && low[u] == tin[u]) {
        // edge (p, u) eh ponte
    }
}

void find_bridges() {
    timer = 0;
    for (int i = 0; i < n; i++) tin[i] = low[i] = 0;
    for (int i = 0; i < n; i++)
        if (tin[i] == 0) dfs_bridge(i);
}
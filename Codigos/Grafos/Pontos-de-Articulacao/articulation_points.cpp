const int N = 3e5 + 5;
int n, m, timer;
vector<int> adj[N];
int tin[N], low[N];

void dfs(int u, int p = -1) {
    low[u] = tin[u] = ++timer;
    int child = 0;
    for (int v : adj[u]) {
        if (tin[v] != 0 && v != p) {
            low[u] = min(low[u], tin[v]);
        } else if (v != p) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (p != -1 && low[v] >= tin[u]) {
                // vertice u eh um ponto de articulacao
            }
            child++;
        }
    }
    if (p == -1 && child > 1) {
        // vertice u eh um ponto de articulacao
    }
}

void find_articulation_points() {
    timer = 0;
    for (int i = 0; i < n; i++) tin[i] = low[i] = 0;
    for (int i = 0; i < n; i++)
        if (tin[i] == 0) dfs(i);
}

const int N = 3e5 + 5;
int n, m, timer, ncc;
vector<int> adjbcc[N];
vector<int> adj[N];
int tin[N], low[N], ebcc[N];

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
}

void dfs_ebcc(int u, int p, int cc) {
    if (p != -1 && low[u] == tin[u]) {
        // edge (u, p) eh uma ponte
        cc = ++ncc;
    }
    ebcc[u] = cc;
    for (int v : adj[u])
        if (ebcc[v] == -1) dfs_ebcc(v, u, cc);
}

void build_ebcc_graph() {
    ncc = timer = 0;
    for (int i = 0; i < n; i++) {
        tin[i] = low[i] = 0;
        ebcc[i] = -1;
        adjbcc[i].clear();
    }
    for (int i = 0; i < n; i++)
        if (tin[i] == 0) dfs_bridge(i);
    for (int i = 0; i < n; i++)
        if (ebcc[i] == -1) dfs_ebcc(i, -1, ncc), ++ncc;
    // Opcao 1 - constroi o grafo comprimido passando por todas as edges
    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) {
            if (ebcc[u] != ebcc[v]) {
                adjbcc[ebcc[u]].emplace_back(ebcc[v]);
            } else {
                // faz algo
            }
        }
    }
    // Opcao 2 - constroi o grafo comprimido passando so pelas pontes
    // for (auto [u, v] : bridges) {
    //     adjbcc[ebcc[u]].emplace_back(ebcc[v]);
    //     adjbcc[ebcc[v]].emplace_back(ebcc[u]);
    // }
}
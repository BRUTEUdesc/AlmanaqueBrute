const int N = 3e5 + 5;
int n, m, timer, ncc, edge_id;
vector<int> adjbcc[N];
vector<pair<int, int>> adj[N]; // {to, edge id}
int tin[N], low[N], ebcc[N];

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
}

void dfs_ebcc(int u, int p, int cc) {
    if (p != -1 && low[u] == tin[u]) {
        // edge (u, p) eh uma ponte
        cc = ++ncc;
    }
    ebcc[u] = cc;
    for (auto [v, _] : adj[u])
        if (ebcc[v] == -1) dfs_ebcc(v, u, cc);
}

void build_ebcc_graph() {
    ncc = timer = edge_id = 0;
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
        for (auto [v, _] : adj[u]) {
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

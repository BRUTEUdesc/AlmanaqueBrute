const int N = 5e5 + 5;
int n, timer;
int tin[N];
vector<int> adj[N];
vector<pair<int, int>> prof;

void et_dfs(int u, int p, int h) {
    tin[u] = timer++;
    prof.emplace_back(h, u);
    for (int v : adj[u]) {
        if (v != p) {
            et_dfs(v, u, h + 1);
            prof.emplace_back(h, u);
        }
    }
    timer++;
}

int lca(int u, int v) {
    int l = tin[u], r = tin[v];
    if (l > r) {
        swap(l, r);
    }
    return st_lca.query(l, r).second;
}

void build() {
    timer = 0;
    prof.clear();
    et_dfs(0, -1, 0);
    st_lca.build(prof);
}
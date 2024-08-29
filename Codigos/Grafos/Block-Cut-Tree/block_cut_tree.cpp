struct Bct {
    int T;
    vector<int> tin, low, stk, art, id, splits;
    vector<vector<int>> adj, g, comp, up;
    int n, sz, m;
    void build(int _n, int _m) {
        n = _n, m = _m;
        adj.resize(n);
    }
    void add_edge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    void dfs(int u, int p) {
        low[u] = tin[u] = ++T;
        stk.emplace_back(u);
        for (auto v : adj[u]) {
            if (tin[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    int x;
                    sz++;
                    do {
                        assert(stk.size());
                        x = stk.back();
                        stk.pop_back();
                        comp[x].emplace_back(sz);
                    } while (x != v);
                    comp[u].emplace_back(sz);
                }
            } else if (v != p) {
                low[u] = min(low[u], tin[v]);
            }
        }
    }
    inline bool is_articulation_point(int u) { return art[id[u]]; }
    inline int number_of_splits(int u) { return splits[id[u]]; }
    void work() {
        T = sz = 0;
        stk.clear();
        tin.resize(n, -1);
        comp.resize(n);
        low.resize(n);
        for (int i = 0; i < n; i++)
            if (tin[i] == -1) dfs(i, 0);
        art.resize(sz + n + 1);
        splits.resize(n + sz + 1, 1);
        id.resize(n);
        g.resize(sz + n + 1);
        for (int i = 0; i < n; i++) {
            if ((int)comp[i].size() > 1) {
                id[i] = ++sz;
                art[id[i]] = 1;
                splits[id[i]] = (int)comp[i].size();
                for (auto u : comp[i]) {
                    g[id[i]].emplace_back(u);
                    g[u].emplace_back(id[i]);
                }
            } else if (comp[i].size()) {
                id[i] = comp[i][0];
            }
        }
    }
};

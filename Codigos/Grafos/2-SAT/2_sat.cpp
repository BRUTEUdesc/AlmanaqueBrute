struct sat2 {
    int n;
    vector<vector<int>> g, rg;
    vector<bool> vis, assignment;
    vector<int> topo, comp;

    void build(int _n) {
        n = 2 * _n;
        g.assign(n, vector<int>());
        rg.assign(n, vector<int>());
    }

    int get(int u) {
        if (u < 0) return 2 * (~u) + 1;
        else return 2 * u;
    }

    void add_impl(int u, int v) {
        u = get(u), v = get(v);
        g[u].push_back(v);
        rg[v].push_back(u);
        g[v ^ 1].push_back(u ^ 1);
        rg[u ^ 1].push_back(v ^ 1);
    }

    void add_or(int u, int v) { add_impl(~u, v); }

    void add_and(int u, int v) {
        add_or(u, u);
        add_or(v, v);
    }

    void add_xor(int u, int v) {
        add_impl(u, ~v);
        add_impl(~u, v);
    }

    void add_equals(int u, int v) {
        add_impl(u, v);
        add_impl(~u, ~v);
    }

    void toposort(int u) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v]) toposort(v);
        topo.push_back(u);
    }

    void dfs(int u, int cc) {
        comp[u] = cc;
        for (int v : rg[u])
            if (comp[v] == -1) dfs(v, cc);
    }

    pair<bool, vector<bool>> solve() {
        topo.clear();
        vis.assign(n, false);

        for (int i = 0; i < n; i++)
            if (!vis[i]) toposort(i);
        reverse(topo.begin(), topo.end());

        comp.assign(n, -1);
        int cc = 0;
        for (auto u : topo)
            if (comp[u] == -1) dfs(u, cc++);

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1]) return {false, {}};
            assignment[i / 2] = comp[i] > comp[i + 1];
        }

        return {true, assignment};
    }
};

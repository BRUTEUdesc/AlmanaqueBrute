struct sat2 {
    int n;
    vector<vector<int>> g, gt;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    // number of variables
    sat2(int _n) {
        n = 2 * (_n + 5);
        g.assign(n, vector<int>());
        gt.assign(n, vector<int>());
    }
    void add_edge(int v, int u, bool v_sign, bool u_sign) {
        g[2 * v + v_sign].push_back(2 * u + !u_sign);
        g[2 * u + u_sign].push_back(2 * v + !v_sign);
        gt[2 * u + !u_sign].push_back(2 * v + v_sign);
        gt[2 * v + !v_sign].push_back(2 * u + u_sign);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : g[v]) {
            if (!used[u]) { dfs1(u); }
        }
        order.push_back(v);
    }
    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : gt[v]) {
            if (comp[u] == -1) { dfs2(u, cl); }
        }
    }
    bool solve() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) { dfs1(i); }
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1) { dfs2(v, j++); }
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1]) { return false; }
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }
};

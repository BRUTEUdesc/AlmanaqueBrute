struct BinaryLifting {
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> up, st;
    vector<int> tin, tout;
    int N, LG, t;

    const int neutral = 0;
    int merge(int l, int r) { return l + r; }

    void dfs(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
            st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
        }
        for (auto [w, v] : adj[u])
            if (v != p) {
                up[v][0] = u, st[v][0] = w;
                dfs(v, u);
            }
        tout[u] = t++;
    }

    void build(int root, vector<vector<pair<int, int>>> adj2) {
        t = 1;
        N = (int)adj2.size();
        LG = 32 - __builtin_clz(N);
        adj = adj2;
        tin = tout = vector<int>(N);
        up = st = vector(N, vector<int>(LG, neutral));
        up[root][0] = root;
        dfs(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int query2(int u, int v) {
        if (ancestor(u, v))
            return neutral;
        int ans = neutral;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                ans = merge(ans, st[u][i]);
                u = up[u][i];
            }
        }
        return merge(ans, st[u][0]);
    }

    int query(int u, int v) {
        if (u == v)
            return neutral;
#warning TRATAR ESSE CASO ACIMA
        return merge(query2(u, v), query2(v, u));
    }
} bl;

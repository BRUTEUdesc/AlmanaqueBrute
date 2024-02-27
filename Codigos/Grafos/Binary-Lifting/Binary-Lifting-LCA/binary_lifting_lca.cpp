struct BinaryLifting {
    vector<vector<int>> adj, up;
    vector<int> tin, tout;
    int N, LG, t;

    void dfs(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
        }
        for (int v : adj[u])
            if (v != p) {
                up[v][0] = u;
                dfs(v, u);
            }
        tout[u] = t++;
    }

    void build(int root, vector<vector<int>> adj2) {
        t = 1;
        N = (int)adj2.size();
        LG = 32 - __builtin_clz(N);
        adj = adj2;
        tin = tout = vector<int>(N);
        up = vector(N, vector<int>(LG));
        up[root][0] = root;
        dfs(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int lca(int u, int v) {
        if (ancestor(u, v)) {
            return u;
        }
        if (ancestor(v, u)) {
            return v;
        }
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    int kth(int u, int k) {
        for (int i = 0; i < LG; i++) {
            if (k & (1 << i)) {
                u = up[u][i];
            }
        }
        return u;
    }

} bl;

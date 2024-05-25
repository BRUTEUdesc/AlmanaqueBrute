const int N = 3e5 + 5, LG = 20;
vector<int> adj[N];

namespace bl {
    int t, up[N][LG], st[N][LG], tin[N], tout[N], val[N];

    const int neutral = 0;
    int merge(int l, int r) { return l + r; }

    void dfs(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
            st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
        }
        for (int v : adj[u])
            if (v != p) {
                up[v][0] = u, st[v][0] = val[u];
                dfs(v, u);
            }
        tout[u] = t++;
    }

    void build(int root) {
        t = 1;
        up[root][0] = root;
        st[root][0] = neutral;
        dfs(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int query2(int u, int v, bool include_lca) {
        if (ancestor(u, v))
            return include_lca ? val[u] : neutral;
        int ans = val[u];
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                ans = merge(ans, st[u][i]);
                u = up[u][i];
            }
        }
        return include_lca ? merge(ans, st[u][0]) : ans;
    }

    int query(int u, int v) {
        if (u == v) {
            return val[u];
        }
        return merge(query2(u, v, 1), query2(v, u, 0));
    }

    int lca(int u, int v) {
        if (ancestor(u, v))
            return u;
        if (ancestor(v, u))
            return v;
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

}

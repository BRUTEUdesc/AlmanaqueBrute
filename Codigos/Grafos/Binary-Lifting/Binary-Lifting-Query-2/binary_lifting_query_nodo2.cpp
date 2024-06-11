struct node {
    int pref, suff, sum, best;
    node() : pref(0), suff(0), sum(0), best(0) {}
    node(int x) : pref(x), suff(x), sum(x), best(x) {}
    node(int a, int b, int c, int d) : pref(a), suff(b), sum(c), best(d) {}
};

node merge(node l, node r) {
    int pref = max(l.pref, l.sum + r.pref);
    int suff = max(r.suff, r.sum + l.suff);
    int sum = l.sum + r.sum;
    int best = max(l.suff + r.pref, max(l.best, r.best));
    return node(pref, suff, sum, best);
}

struct BinaryLifting {
    vector<vector<int>> adj, up;
    vector<int> val, tin, tout;
    vector<vector<node>> st, st2;
    int N, LG, t;

    void build(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
            st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
            st2[u][i + 1] = merge(st2[up[u][i]][i], st2[u][i]);
        }
        for (int v : adj[u])
            if (v != p) {
                up[v][0] = u;
                st[v][0] = node(val[u]);
                st2[v][0] = node(val[u]);
                build(v, u);
            }
        tout[u] = t++;
    }

    void build(int root, vector<vector<int>> adj2, vector<int> v) {
        t = 1;
        N = (int)adj2.size();
        LG = 32 - __builtin_clz(N);
        adj = adj2;
        val = v;
        tin = tout = vector<int>(N);
        up = vector(N, vector<int>(LG));
        st = st2 = vector(N, vector<node>(LG));
        up[root][0] = root;
        st[root][0] = node(val[root]);
        st2[root][0] = node(val[root]);
        build(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    node query2(int u, int v, bool include_lca, bool invert) {
        if (ancestor(u, v)) return include_lca ? node(val[u]) : node();
        node ans = node(val[u]);
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                if (invert) ans = merge(st2[u][i], ans);
                else ans = merge(ans, st[u][i]);
                u = up[u][i];
            }
        }
        return include_lca ? merge(ans, st[u][0]) : ans;
    }

    node query(int u, int v) {
        if (u == v) return node(val[u]);
        node l = query2(u, v, 1, 0);
        node r = query2(v, u, 0, 1);
        return merge(l, r);
    }

    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = LG - 1; i >= 0; i--)
            if (!ancestor(up[u][i], v)) u = up[u][i];
        return up[u][0];
    }

} bl, bl2;

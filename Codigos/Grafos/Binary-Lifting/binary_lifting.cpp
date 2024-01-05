namespace st {
    int n, me;
    vector<vector<int>> st;
    void bl_dfs(int u, int p) {
        st[u][0] = p;
        for (int i = 1; i <= me; i++) {
            st[u][i] = st[st[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                bl_dfs(v, u);
            }
        }
    }
    void build(int _n, int root = 0) {
        n = _n;
        me = floor(log2(n));
        st.assign(n, vector<int>(me + 1, 0));
        bl_dfs(root, root);
    }
    int ancestor(int u,
                 int k) { // k-th ancestor of u
        for (int i = me; i >= 0; i--) {
            if ((1 << i) & k) {
                u = st[u][i];
            }
        }
        return u;
    }
}

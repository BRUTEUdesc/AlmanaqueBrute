namespace hld {
    const int MAX = 2e5 + 5;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    bool e = 0;
    ll merge(ll a, ll b) {
        return max(a, b); // how to merge paths
    }
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) {
                    swap(v, adj[u][0]);
                }
            }
        }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (int v : adj[u]) {
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
        }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<ll> v, vector<vector<int>> adj2) {
        build(root);
        vector<ll> aux(v.size());
        for (int i = 0; i < (int)v.size(); i++) {
            aux[pos[i]] = v[i];
        }
        seg::build(aux);
    }
    void build(int root, vector<i3> &edges) { // use this if
                                    // weighted edges
        build(root);
        e = 1;
        vector<ll> aux(edges.size() + 1);
        for (auto [u, v, w] : edges) {
            if (pos[u] > pos[v]) {
                swap(u, v);
            }
            aux[pos[v]] = w;
        }
        seg::build(aux);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            return seg::query(pos[u] + e, pos[v]);
        } else {
            ll qv = seg::query(pos[head[v]], pos[v]);
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, int v, ll k) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            seg::update(pos[u] + e, pos[v], k);
        } else {
            seg::update(pos[head[v]], pos[v], k);
            update(u, pai[head[v]], k);
        }
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    ll query_subtree(int u) { return seg::query(pos[u], pos[u] + sz[u] - 1); }
}

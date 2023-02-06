namespace hld {
    const int MAX = 2e5+5;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    void dfs_sz(int u, int p=-1) {
        sz[u] = 1;
        for (int &v : adj[u]) if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
        }
    }
    void dfs_hld(int u, int p=-1) {
        pos[u] = t++;
        for (int v : adj[u]) if (v != p) {
            pai[v] = u;
            head[v] = (v == adj[u][0] ? head[u] : v);
            dfs_hld(v, u);
        }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) return seg::query(pos[u], pos[v]); // pos[u]+1 for edges
        else {
            ll qv = seg::query(pos[head[v]], pos[v]);
            ll qu = query(u, pai[head[v]]);
            return max(qu, qv); // how to merge paths
        }
    }
    void update(int u, int v, ll k) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) seg::update(pos[u], pos[v], k); // pos[u]+1 for edges
        else {
            seg::update(pos[head[v]], pos[v], k);
            update(u, pai[head[v]], k);
        }
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    ll query_subtree(int u) {
        return seg::query(pos[u], pos[u]+sz[u]-1);
    }
}

struct HLD {
    int n, t;
    vector<vector<int>> adj;
    vector<int> sz, pos, par, head, who;
    bool e = 0;
    SegTree seg;

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
        who[pos[u] = t++] = u;
        for (int v : adj[u]) {
            if (v != p) {
                par[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
        }
    }
    void build_hld(int u) {
        sz = pos = par = head = who = vector<int>(n);
        dfs_sz(u);
        t = 0;
        par[u] = u;
        head[u] = u;
        dfs_hld(u);
    }

    void build(int root, vector<ll> v, vector<vector<int>> adj2) {
        // usar esse build pra iniciar com valores nos nodos
        n = (int)adj2.size();
        adj = adj2;
        build_hld(root);
        vector<ll> aux(n);
        for (int i = 0; i < (int)v.size(); i++) {
            aux[pos[i]] = v[i];
        }
        seg.build(aux);
    }
    void build(int root, vector<vector<int>> adj2) {
        // esse build eh para iniciar vazia
        build(root, vector<ll>(adj2.size(), seg.neutral), adj2);
    }
    void build(int root, vector<tuple<int, int, ll>> edges) {
        // usar esse build se os pesos estiverem nas arestas
        n = (int)edges.size() + 1;
        adj = vector<vector<int>>(n);
        for (auto [u, v, w] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        build_hld(root);
        e = 1;
        vector<ll> aux(n);
        for (auto [u, v, w] : edges) {
            if (pos[u] > pos[v]) {
                swap(u, v);
            }
            aux[pos[v]] = w;
        }
        seg.build(aux);
    }

    ll query(int u, int v) {
        if (e && u == v) {
            return seg.neutral;
        }
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            return seg.query(pos[u] + e, pos[v]);
        } else {
            ll qv = seg.query(pos[head[v]], pos[v]);
            ll qu = query(u, par[head[v]]);
            return seg.merge(qu, qv);
        }
    }
    ll query_subtree(int u) {
        if (e && sz[u] == 1) {
            return seg.neutral;
        }
        return seg.query(pos[u], pos[u] + sz[u] - 1);
    }

    void update(int u, int v, ll k, bool replace = false) {
        if (e && u == v) {
            return;
        }
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            seg.update(pos[u] + e, pos[v], k, replace);
        } else {
            seg.update(pos[head[v]], pos[v], k, replace);
            update(u, par[head[v]], k, replace);
        }
    }
    void update_subtree(int u, ll k, bool replace = false) {
        if (e && sz[u] == 1) {
            return;
        }
        seg.update(pos[u], pos[u] + sz[u] - 1, k, replace);
    }

    int lca(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        return (head[u] == head[v] ? u : lca(u, par[head[v]]));
    }
} hld;
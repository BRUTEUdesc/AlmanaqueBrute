const int N = 3e5 + 5;

vector<pair<int, ll>> adj[N];

namespace HLD {
    int t, sz[N], pos[N], par[N], head[N];
    SegTree seg; // por padrao, a HLD esta codada para usar a SegTree lazy,
                 // mas pode usar qualquer estrutura de dados aqui
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            auto &[v, w] = adj[u][i];
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0].first] || adj[u][0].first == p) {
                    swap(adj[u][0], adj[u][i]);
                }
            }
        }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (auto [v, w] : adj[u]) {
            if (v != p) {
                par[v] = u;
                head[v] = (v == adj[u][0].first ? head[u] : v);
                dfs_hld(v, u);
            }
        }
    }
    void build_hld(int u) {
        dfs_sz(u);
        t = 0, par[u] = u, head[u] = u;
        dfs_hld(u);
    }
    void build(int n, int root) {
        build_hld(root);
        vector<ll> aux(n, seg.neutral);
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (u == par[v]) {
                    aux[pos[v]] = w;
                }
            }
        }
        seg.build(aux);
    }
    ll query(int u, int v) {
        if (u == v) return seg.neutral;
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            return seg.query(pos[u] + 1, pos[v]);
        } else {
            ll qv = seg.query(pos[head[v]], pos[v]);
            ll qu = query(u, par[head[v]]);
            return seg.merge(qu, qv);
        }
    }
    ll query_subtree(int u) {
        if (sz[u] == 1) return seg.neutral;
        return seg.query(pos[u] + 1, pos[u] + sz[u] - 1);
    }
    // a flag repl diz se o update é de soma ou de replace
    void update(int u, int v, ll k, bool repl) {
        if (u == v) return;
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            seg.update(pos[u] + 1, pos[v], k, repl);
        } else {
            seg.update(pos[head[v]], pos[v], k, repl);
            update(u, par[head[v]], k, repl);
        }
    }
    void update_subtree(int u, ll k, bool repl) {
        if (sz[u] == 1) return;
        seg.update(pos[u] + 1, pos[u] + sz[u] - 1, k, repl);
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return head[u] == head[v] ? u : lca(u, par[head[v]]);
    }
}

const int N = 3e5 + 5;

vector<int> adj[N];

namespace HLD {
    int t, sz[N], pos[N], par[N], head[N];
    SegTree seg; // por padrao, a HLD esta codada para usar a SegTree lazy,
                 // mas pode usar qualquer estrutura de dados aqui
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
            }
        }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (int v : adj[u]) {
            if (v != p) {
                par[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
        }
    }
    void build_hld(int u) {
        dfs_sz(u);
        t = 0, par[u] = u, head[u] = u;
        dfs_hld(u);
    }
    void build(vector<ll> v, int root) { // pra buildar com valores nos nodos
        build_hld(root);
        vector<ll> aux(v.size());
        for (int i = 0; i < (int)v.size(); i++) aux[pos[i]] = v[i];
        seg.build(aux);
    }
    void build(int n, int root) { // pra buildar com neutro nos nodos
        build(vector<ll>(n, seg.neutral), root);
    }
    void build(ll *bg, ll *ed, int root) { // pra buildar com array de C
        build(vector<ll>(bg, ed), root);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            return seg.query(pos[u], pos[v]);
        } else {
            ll qv = seg.query(pos[head[v]], pos[v]);
            ll qu = query(u, par[head[v]]);
            return seg.merge(qu, qv);
        }
    }
    ll query_subtree(int u) {
        return seg.query(pos[u], pos[u] + sz[u] - 1);
    }
    // a flag repl diz se o update é de soma ou de replace
    void update(int u, int v, ll k, bool repl) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            seg.update(pos[u], pos[v], k, repl);
        } else {
            seg.update(pos[head[v]], pos[v], k, repl);
            update(u, par[head[v]], k, repl);
        }
    }
    void update_subtree(int u, ll k, bool repl) {
        seg.update(pos[u], pos[u] + sz[u] - 1, k, repl);
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return head[u] == head[v] ? u : lca(u, par[head[v]]);
    }
}
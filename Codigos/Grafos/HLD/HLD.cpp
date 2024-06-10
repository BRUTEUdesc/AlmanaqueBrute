const int N = 3e5 + 5;

vector<int> adj[N];
int sz[N], pos[N], par[N], head[N];

namespace HLD {
    int t;
    bool e = 0; // flag pra dizer se eh de aresta ou nao
    SegTree ds; // pode usar qualquer estrutura de dados aqui

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
        t = 0;
        par[u] = u;
        head[u] = u;
        dfs_hld(u);
    }

    void build(int root, vector<ll> v) {
        // usar esse build pra iniciar com valores nos nodos
        // (para iniciar vazia, passar o vetor com valores neutros)
        build_hld(root);
        vector<ll> aux(v.size());
        for (int i = 0; i < (int)v.size(); i++) aux[pos[i]] = v[i];
        ds.build(aux);
    }

    void build(int root, vector<tuple<int, int, ll>> edges) {
        // usar esse build se os valores estiverem nas arestas
        for (auto [u, v, w] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        build_hld(root);
        e = 1;
        assert(edges.size() >= 1);
        vector<ll> aux(edges.size() - 1);
        for (auto [u, v, w] : edges) {
            if (pos[u] > pos[v]) swap(u, v);
            aux[pos[v]] = w;
        }
        ds.build(aux);
    }

    ll query(int u, int v) {
        if (e && u == v) return ds.neutral;
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            return ds.query(pos[u] + e, pos[v]);
        } else {
            ll qv = ds.query(pos[head[v]], pos[v]);
            ll qu = query(u, par[head[v]]);
            return ds.merge(qu, qv);
        }
    }
    ll query_subtree(int u) {
        if (e && sz[u] == 1) return ds.neutral;
        return ds.query(pos[u] + e, pos[u] + sz[u] - 1);
    }

    void update(int u, int v, ll k, bool replace = false) {
        if (e && u == v) return;
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            ds.update(pos[u] + e, pos[v], k, replace);
        } else {
            ds.update(pos[head[v]], pos[v], k, replace);
            update(u, par[head[v]], k, replace);
        }
    }
    void update_subtree(int u, ll k, bool replace = false) {
        if (e && sz[u] == 1) return;
        ds.update(pos[u] + e, pos[u] + sz[u] - 1, k, replace);
    }

    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return head[u] == head[v] ? u : lca(u, par[head[v]]);
    }
}
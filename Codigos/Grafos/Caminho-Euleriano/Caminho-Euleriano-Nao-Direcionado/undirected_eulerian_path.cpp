const int MAXN = 1e6 + 6, MAXM = 2e6 + 6;

vector<pair<int, int>> adj[MAXN]; // {nodo, id da aresta}

struct EulerianTrail {
    int n, m;
    int it[MAXN], deg[MAXN], vis_edge[MAXM];
    void build(int _n, int _m) {
        n = _n;
        m = _m;
        for (int i = 0; i < n; i++) {
            it[i] = deg[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            vis_edge[i] = 0;
        }
    }
    vector<int> find() {
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            deg[i] = (int)adj[i].size();
        }
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            debug(i, deg[i], start, end);
            if (deg[i] & 1) {
                if (start == -1) {
                    start = i;
                } else if (end == -1) {
                    end = i;
                } else {
                    return {};
                }
            }
        }
        if (start == -1 && end == -1) {
            // pode comecar em qualquer vertice com alguma aresta (mas tem que terminar nele tambem)
            // nesse caso eh ciclo euleriano
            for (int i = 0; i < n; i++) {
                if (deg[i] > 0) {
                    start = i;
                    end = i;
                    break;
                }
            }
            assert(start != -1);
        } else if (start == -1 || end == -1) {
            return {};
        }
        function<void(int)> dfs_et = [&](int u) {
            while (it[u] < (int)adj[u].size()) {
                auto [v, id] = adj[u][it[u]++];
                if (vis_edge[id]) {
                    continue;
                }
                vis_edge[id] = 1;
                dfs_et(v);
            }
            cur.push_back(u);
        };
        dfs_et(start);
        debug(cur, m);
        if ((int)cur.size() != m + 1) {
            return {};
        }
        reverse(cur.begin(), cur.end());
        return cur;
    }
} et_finder;
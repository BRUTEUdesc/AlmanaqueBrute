struct NegativeCycleFinder {
    const ll INF = 1e18;
    int n;
    vector<tuple<int, int, ll>> edges;
    void build(int _n) { n = _n; }
    void add_edge(int u, int v, ll w) { edges.emplace_back(u, v, w); }
    vector<int> get_cycle() {
        vector<ll> d(n);
        vector<int> p(n, -1);
        int x;
        for (int i = 0; i < n; ++i) {
            x = -1;
            for (auto [u, v, w] : edges) {
                if (d[u] < INF) {
                    if (d[u] + w < d[v]) {
                        d[v] = max(-INF, d[u] + w);
                        p[v] = u;
                        x = v;
                    }
                }
            }
        }
        vector<int> cycle;
        if (x != -1) {
            for (int i = 0; i < n; ++i) x = p[x];
            for (int v = x;; v = p[v]) {
                cycle.push_back(v);
                if (v == x && cycle.size() > 1) break;
            }
            reverse(cycle.begin(), cycle.end());
        }
        return cycle;
    }
} finder;

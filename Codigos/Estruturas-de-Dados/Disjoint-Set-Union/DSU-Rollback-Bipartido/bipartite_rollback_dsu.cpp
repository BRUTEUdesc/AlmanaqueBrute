struct BipartiteRollback_DSU {
    vector<int> par, sz, c, bip;
    int all_bipartite;
    stack<stack<pair<int &, int>>> changes;
    void build(int n) {
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        c.assign(n, 0);
        bip.assign(n, 1);
        all_bipartite = true;
        changes.emplace();
    }
    int find(int a) { return a == par[a] ? a : find(par[a]); }
    int color(int a) { return a == par[a] ? c[a] : c[a] ^ color(par[a]); }
    bool bipartite(int a) { return bip[find(a)]; }
    void checkpoint() { changes.emplace(); }
    void change(int &a, int b) {
        changes.top().emplace(a, a);
        a = b;
    }
    bool unite(int a, int b) {
        bool equal_color = color(a) == color(b);
        a = find(a), b = find(b);
        if (a == b) {
            if (equal_color) {
                change(bip[a], 0);
                change(all_bipartite, 0);
            }
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        change(par[b], a);
        change(sz[a], sz[a] + sz[b]);
        change(bip[a], bip[a] && bip[b]);
        change(all_bipartite, all_bipartite && bip[a]);
        if (equal_color) change(c[b], 1);
        return true;
    }
    void rollback() {
        while (changes.top().size()) {
            auto [a, b] = changes.top().top();
            a = b;
            changes.top().pop();
        }
        changes.pop();
    }
};
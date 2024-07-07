struct Bipartite_DSU {
    vector<int> par, sz, c, bip;
    bool all_bipartite;
    void build(int n) {
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        c.assign(n, 0);
        bip.assign(n, 1);
        all_bipartite = true;
    }
    int find(int a) { return a == par[a] ? a : find(par[a]); }
    int color(int a) { return a == par[a] ? c[a] : c[a] ^ color(par[a]); }
    bool bipartite(int a) { return bip[find(a)]; }
    bool unite(int a, int b) {
        bool equal_color = color(a) == color(b);
        a = find(a), b = find(b);
        if (a == b) {
            if (equal_color) {
                bip[a] = 0;
                all_bipartite = 0;
            }
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        if (equal_color) c[b] = 1;
        bip[a] &= bip[b];
        all_bipartite &= bip[a];
        return true;
    }
};

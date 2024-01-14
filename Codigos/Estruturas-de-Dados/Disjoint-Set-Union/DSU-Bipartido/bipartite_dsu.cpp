struct Bipartite_DSU {
    vector<int> par, sz, c, bip;
    int number_of_sets;
    Bipartite_DSU(int n = 0) : par(n), sz(n, 1), c(n), bip(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) {
        return a == par[a] ? a : find(par[a]);
    }
    int color (int a) {
        return a == par[a] ? c[a] : c[a] ^ color(par[a]);
    }
    bool bipartite(int a) {
        return bip[find(a)];
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            if (color(a) == color(b)) {
                bip[a] = 0;
            }
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        number_of_sets--;
        par[b] = a;
        sz[a] += sz[b];
        if (color(a) == color(b)) {
            c[b] = 1;
        }
        bip[a] &= bip[b];
        return true;
    }
};

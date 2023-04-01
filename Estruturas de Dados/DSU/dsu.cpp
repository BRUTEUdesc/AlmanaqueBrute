struct DSU {
    vector<int> pa, sz;
    DSU(int n) : pa(n + 1), sz(n + 1, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int root(int a) { return pa[a] = (a == pa[a] ? a : root(pa[a])); }
    bool find(int a, int b) { return root(a) == root(b); }
    void uni(int a, int b) {
        int ra = root(a), rb = root(b);
        if (ra == rb) return;
        if (sz[ra] > sz[rb]) swap(ra, rb);
        pa[ra] = rb;
        sz[rb] += sz[ra];
    }
};

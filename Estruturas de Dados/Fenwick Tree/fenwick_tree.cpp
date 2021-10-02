struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n) { tree.assign(n, 0); }
    FenwickTree(vector<int> v) : FenwickTree(v.size()) {
        for (size_t i = 1; i < v.size(); i++) update(i, v[i]);
    }
    int lsONE(int x) { return x & (-x); }
    int query(int x) {
        int soma = 0;
        for (; x > 0; x -= lsONE(x)) soma += tree[x];
        return soma;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int x, int v) {
        for (; x < n; x += lsONE(x)) tree[x] += v;
    }
};

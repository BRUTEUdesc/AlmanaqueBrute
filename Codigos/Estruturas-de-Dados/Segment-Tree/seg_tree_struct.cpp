struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n) { tree.assign(4 * n, 0); }

    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }

    int query(int n, int esq, int dir, int l, int r) {
        if (esq > r || dir < l) { return 0; }
        if (l <= esq && dir <= r) { return tree[n]; }
        int mid = (esq + dir) / 2;
        return max(query(le(n), esq, mid, l, r), query(ri(n), mid + 1, dir, l, r));
    }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

    void update(int n, int esq, int dir, int x, int v) {
        if (esq > x || dir < x) { return; }
        if (esq == dir) {
            tree[n] = v;
        } else {
            int mid = (esq + dir) / 2;
            if (x <= mid) {
                update(le(n), esq, mid, x, v);
            } else {
                update(ri(n), mid + 1, dir, x, v);
            }
            tree[n] = max(tree[le(n)], tree[ri(n)]);
        }
    }
    void update(int x, int v) { update(0, 0, n - 1, x, v); }
};

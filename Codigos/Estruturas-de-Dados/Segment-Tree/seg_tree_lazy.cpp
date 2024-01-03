namespace seg {
    const int MAX = 2e5 + 5;
    const ll NEUTRAL = 0; // merge(a, neutral) = a
    ll merge(ll a, ll b) { return a + b; }
    int sz; // size of the array
    ll tree[4 * MAX], lazy[4 * MAX];
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void push(int n, int esq, int dir) {
        if (lazy[n] == 0) { return; }
        tree[n] += lazy[n] * (dir - esq + 1);
        if (esq != dir) {
            lazy[le(n)] += lazy[n];
            lazy[ri(n)] += lazy[n];
        }
        lazy[n] = 0;
    }
    void build(span<const ll> v, int n, int esq, int dir) {
        if (esq == dir) {
            tree[n] = v[esq];
        } else {
            int mid = (esq + dir) / 2;
            build(v, le(n), esq, mid);
            build(v, ri(n), mid + 1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(span<const ll> v) {
        sz = v.size();
        build(v, 0, 0, sz - 1);
    }
    ll query(int l, int r, int n = 0, int esq = 0, int dir = sz - 1) {
        push(n, esq, dir);
        if (esq > r || dir < l) { return NEUTRAL; }
        if (l <= esq && dir <= r) { return tree[n]; }
        int mid = (esq + dir) / 2;
        return merge(query(l, r, le(n), esq, mid), query(l, r, ri(n), mid + 1, dir));
    }
    void update(int l, int r, ll v, int n = 0, int esq = 0, int dir = sz - 1) {
        push(n, esq, dir);
        if (esq > r || dir < l) { return; }
        if (l <= esq && dir <= r) {
            lazy[n] += v;
            push(n, esq, dir);
        } else {
            int mid = (esq + dir) / 2;
            update(l, r, v, le(n), esq, mid);
            update(l, r, v, ri(n), mid + 1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
}

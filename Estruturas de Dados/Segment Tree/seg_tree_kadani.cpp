namespace seg {
    const int MAX = 1e5+5;
    struct node {
        ll pref, suff, sum, best;
    };
    node new_node(ll v) { return node{v, v, v, v}; }
    const node NEUTRAL = {0, 0, 0, 0};
    node tree[4*MAX];
    node merge(node a, node b) {
        ll pref = max(a.pref, a.sum + b.pref);
        ll suff = max(b.suff, b.sum + a.suff);
        ll sum = a.sum + b.sum;
        ll best = max(a.suff + b.pref, max(a.best, b.best));
        return node{pref, suff, sum, best};
    }

    int n;
    int le(int n) { return 2*n+1; }
    int ri(int n) { return 2*n+2; }
    void build(int n, int esq, int dir, const vector<ll> &v) {
        if (esq == dir) tree[n] = new_node(v[esq]);
        else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid, v);
            build(ri(n), mid+1, dir, v);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(const vector<ll> &v) { n = v.size(); build(0, 0, n-1, v); }
    node query(int n, int esq, int dir, int l, int r) {
        if (esq > r || dir < l) return NEUTRAL;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir) / 2;
        return merge(query(le(n), esq, mid, l, r), query(ri(n), mid+1, dir, l, r));
    }
    ll query(int l, int r) { return query(0, 0, n-1, l, r).best; }
    void update(int n, int esq, int dir, int x, ll v) {
        if (esq > x || dir < x) return;
        if (esq == dir) tree[n] = new_node(v);
        else {
            int mid = (esq + dir) / 2;
            if (x <= mid) update(le(n), esq, mid, x, v);
            else update(ri(n), mid+1, dir, x, v);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void update(int x, ll v) { update(0, 0, n-1, x, v); }
}

struct SegTree {
    using ii = pair<ll, ll>;
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;
    int n;
    vector<ll> t;
    vector<ii> lazy;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    void push(int p, int l, int r) {
        if (lazy[p].second) {
            auto [a, d] = lazy[p];
            t[p] += a * (r - l + 1) + d * (r - l) * (r - l + 1) / 2;
            if (l != r) {
                int mid = (l + r) / 2;
                lazy[lc(p)].first += a;
                lazy[lc(p)].second += d;
                lazy[rc(p)].first += a + (mid + 1 - l) * d;
                lazy[rc(p)].second += d;
            }
            lazy[p] = ii(0, 0);
        }
    }
    void build(int p, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[p] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(lc(p), l, mid, v);
            build(rc(p), mid + 1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 4, neutral);
    }
    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }
    ll query(int p, int l, int r, int L, int R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int p, int l, int r, int L, int R, ii pa) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            auto [a, d] = pa;
            lazy[p] = ii(a + (l - L) * d, d);
            push(p, l, r);
        } else {
            int mid = (l + r) / 2;
            update(lc(p), l, mid, L, R, pa);
            update(rc(p), mid + 1, r, L, R, pa);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void update(int l, int r, ll a0, ll d) { update(1, 0, n - 1, l, r, ii(a0, d)); }
} seg;

struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    int n;
    vector<ll> t;

    void build(int u, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[u] = v[l];
        } else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n << 2, neutral);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    ll query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        ll ql = query(u << 1, l, mid, L, R);
        ll qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, ll x) {
        if (l == r) {
            t[u] += x; // soma
            // t[u] = x; // substitui
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(u << 1, l, mid, i, x);
            } else {
                update(u << 1 | 1, mid + 1, r, i, x);
            }
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int i, ll x) { update(1, 0, n - 1, i, x); }
};

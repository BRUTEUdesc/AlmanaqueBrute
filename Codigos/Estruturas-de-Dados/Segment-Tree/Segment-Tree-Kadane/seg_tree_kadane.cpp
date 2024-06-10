struct SegTree {
    struct node {
        ll sum, pref, suf, ans;
    };
    const node neutral = {0, 0, 0, 0};
    node merge(const node &a, const node &b) {
        return {a.sum + b.sum,
                max(a.pref, a.sum + b.pref),
                max(b.suf, b.sum + a.suf),
                max({a.ans, b.ans, a.suf + b.pref})};
    }

    int n;
    vector<node> t;

    void build(int p, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[p] = {v[l], v[l], v[l], v[l]};
        } else {
            int mid = (l + r) / 2;
            build(p * 2, l, mid, v);
            build(p * 2 + 1, mid + 1, r, v);
            t[p] = merge(t[p * 2], t[p * 2 + 1]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 4, neutral);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n * 4, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    node query(int p, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[p];
        }
        int mid = (l + r) / 2;
        auto ql = query(p * 2, l, mid, L, R);
        auto qr = query(p * 2 + 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r).ans; }

    void update(int p, int l, int r, int i, ll x) {
        if (l == r) {
            t[p] = {x, x, x, x};
        } else {
            int mid = (l + r) / 2;
            if (i <= mid) {
                update(p * 2, l, mid, i, x);
            } else {
                update(p * 2 + 1, mid + 1, r, i, x);
            }
            t[p] = merge(t[p * 2], t[p * 2 + 1]);
        }
    }
    void update(int i, ll x) { update(1, 0, n - 1, i, x); }
};
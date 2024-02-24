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

    void build(int u, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[u] = {v[l], v[l], v[l], v[l]};
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

    void build(ll *bg, ll *en) { // pra construir com array estatico
        n = int(en - bg);
        t.assign(n << 2, neutral);
        vector<ll> aux(n);
        for (int i = 0; i < n; i++) {
            aux[i] = bg[i];
        }
        build(1, 0, n - 1, aux);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }

    node query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        node ql = query(u << 1, l, mid, L, R);
        node qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r).ans; }

    void update(int u, int l, int r, int i, ll x) {
        if (l == r) {
            t[u] = {x, x, x, x};
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
struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    int n;
    vector<ll> t, lazy;
    vector<bool> replace;

    void push(int u, int l, int r) {
        if (replace[u]) {
            t[u] = lazy[u] * (r - l + 1);
            if (l != r) {
                lazy[u << 1] = lazy[u];
                lazy[u << 1 | 1] = lazy[u];
                replace[u << 1] = replace[u];
                replace[u << 1 | 1] = replace[u];
            }
        } else if (lazy[u] != 0) {
            t[u] += lazy[u] * (r - l + 1);
            if (l != r) {
                lazy[u << 1] += lazy[u];
                lazy[u << 1 | 1] += lazy[u];
            }
        }
        replace[u] = false;
        lazy[u] = 0;
    }

    void build(int u, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[u] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n << 2, neutral);
        lazy.assign(n << 2, 0);
        replace.assign(n << 2, false);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n << 2, neutral);
        lazy.assign(n << 2, 0);
        replace.assign(n << 2, false);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    ll query(int u, int l, int r, int L, int R) {
        push(u, l, r);
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

    void update(int u, int l, int r, int L, int R, ll val, bool repl) {
        push(u, l, r);
        if (l > R || r < L) {
            return;
        }
        if (l >= L && r <= R) {
            lazy[u] = val;
            replace[u] = repl;
            push(u, l, r);
        } else {
            int mid = (l + r) >> 1;
            update(u << 1, l, mid, L, R, val, repl);
            update(u << 1 | 1, mid + 1, r, L, R, val, repl);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int l, int r, ll val, bool repl = false) {
        update(1, 0, n - 1, l, r, val, repl);
    }
};
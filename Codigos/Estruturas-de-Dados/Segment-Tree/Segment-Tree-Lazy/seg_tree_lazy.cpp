struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    int n;
    vector<ll> t, lazy;
    vector<bool> replace;

    void push(int p, int l, int r) {
        if (replace[p]) {
            t[p] = lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[p * 2] = lazy[p];
                lazy[p * 2 + 1] = lazy[p];
                replace[p * 2] = replace[p];
                replace[p * 2 + 1] = replace[p];
            }
        } else if (lazy[p] != 0) {
            t[p] += lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[p * 2] += lazy[p];
                lazy[p * 2 + 1] += lazy[p];
            }
        }
        replace[p] = false;
        lazy[p] = 0;
    }

    void build(int p, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[p] = v[l];
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
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
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
        auto ql = query(p * 2, l, mid, L, R);
        auto qr = query(p * 2 + 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int p, int l, int r, int L, int R, ll val, bool repl) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            int mid = (l + r) / 2;
            update(p * 2, l, mid, L, R, val, repl);
            update(p * 2 + 1, mid + 1, r, L, R, val, repl);
            t[p] = merge(t[p * 2], t[p * 2 + 1]);
        }
    }
    void update(int l, int r, ll val, bool repl = false) {
        update(1, 0, n - 1, l, r, val, repl);
    }
};
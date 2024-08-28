struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    int n;
    vector<ll> t;
    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 2, neutral);
    }
    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 2, neutral);
        for (int i = 0; i < n; i++) t[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) t[i] = merge(t[lc(i)], t[rc(i)]);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }
    ll query(int l, int r) {
        ll ansl = neutral, ansr = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = merge(ansl, t[l++]);
            if (r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr);
    }
    void update(int i, ll x, bool replace = false) {
        i += n;
        t[i] = replace ? x : merge(t[i], x);
        for (i >>= 1; i > 0; i >>= 1) t[i] = merge(t[lc(i)], t[rc(i)]);
    }
} seg;

template <ll MINL = (ll)-1e9 - 5, ll MAXR = (ll)1e9 + 5> struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    vector<ll> t;
    vector<int> Lc, Rc;

    inline int newnode() {
        t.push_back(neutral);
        Lc.push_back(-1);
        Rc.push_back(-1);
        return (int)t.size() - 1;
    }

    inline int le(int p) {
        if (Lc[p] == -1) {
            Lc[p] = newnode();
        }
        return Lc[p];
    }

    inline int ri(int p) {
        if (Rc[p] == -1) {
            Rc[p] = newnode();
        }
        return Rc[p];
    }

    SegTree() { newnode(); }

    ll query(int p, ll l, ll r, ll L, ll R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[p];
        }
        ll mid = l + (r - l) / 2;
        ll ql = query(le(p), l, mid, L, R);
        ll qr = query(ri(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r) { return query(0, MINL, MAXR, l, r); }

    void update(int p, ll l, ll r, ll i, ll x) {
        if (l == r) {
            t[p] += x; // soma
            // t[p] = x; // substitui
            return;
        }
        ll mid = l + (r - l) / 2;
        if (i <= mid) {
            update(le(p), l, mid, i, x);
        } else {
            update(ri(p), mid + 1, r, i, x);
        }
        t[u] = merge(t[le(p)], t[ri(p)]);
    }
    void update(ll i, ll x) { update(0, MINL, MAXR, i, x); }
};
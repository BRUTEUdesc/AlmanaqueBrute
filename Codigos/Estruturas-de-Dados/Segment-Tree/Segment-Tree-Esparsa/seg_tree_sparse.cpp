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

    inline int le(int u) {
        if (Lc[u] == -1) {
            Lc[u] = newnode();
        }
        return Lc[u];
    }

    inline int ri(int u) {
        if (Rc[u] == -1) {
            Rc[u] = newnode();
        }
        return Rc[u];
    }

    SegTree() {
        newnode();
    }

    ll query(int u, ll l, ll r, ll L, ll R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        ll mid = l + (r - l) / 2;
        ll ql = query(le(u), l, mid, L, R);
        ll qr = query(ri(u), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r) { return query(0, MINL, MAXR, l, r); }

    void update(int u, ll l, ll r, ll i, ll x) {
        if (l == r) {
            t[u] += x; // soma
            // t[u] = x; // substitui
            return;
        }
        ll mid = l + (r - l) / 2;
        if (i <= mid) {
            update(le(u), l, mid, i, x);
        } else {
            update(ri(u), mid + 1, r, i, x);
        }
        t[u] = merge(t[le(u)], t[ri(u)]);
    }
    void update(ll i, ll x) { update(0, MINL, MAXR, i, x); }
};
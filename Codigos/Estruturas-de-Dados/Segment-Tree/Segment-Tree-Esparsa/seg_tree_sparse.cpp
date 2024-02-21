template <ll MINL = ll(-1e9 - 5), ll MAXR = ll(1e9 + 5)> struct SegTree {
    const ll neutral = 0;
    struct node {
        ll val;
        int L, R;
        node(ll v) : val(v), L(-1), R(-1) { }
    };
    ll merge(ll a, ll b) { return a + b; }

    vector<node> t;

    int newnode() {
        t.push_back(node(neutral));
        return int(t.size() - 1);
    }

    SegTree() { newnode(); }

    int le(int u) {
        if (t[u].L == -1) {
            t[u].L = newnode();
        }
        return t[u].L;
    }

    int ri(int u) {
        if (t[u].R == -1) {
            t[u].R = newnode();
        }
        return t[u].R;
    }

    ll query(int u, ll l, ll r, ll L, ll R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u].val;
        }
        ll mid = l + (r - l) / 2;
        ll ql = query(le(u), l, mid, L, R);
        ll qr = query(ri(u), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r) { return query(0, MINL, MAXR, l, r); }

    void update(int u, ll l, ll r, ll i, ll x) {
        debug(u, l, r);
        if (l == r) {
            t[u].val += x; // soma
            // t[u].val = x; // substitui
            return;
        }
        ll mid = l + (r - l) / 2;
        if (i <= mid) {
            update(le(u), l, mid, i, x);
        } else {
            update(ri(u), mid + 1, r, i, x);
        }
        t[u].val = merge(t[le(u)].val, t[ri(u)].val);
    }
    void update(ll i, ll x) { update(0, MINL, MAXR, i, x); }
};

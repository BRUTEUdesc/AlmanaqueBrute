template <ll MINL = (ll)-1e9 - 5, ll MAXR = (ll)1e9 + 5> struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    vector<ll> t, lazy;
    vector<int> Lc, Rc;
    vector<bool> replace;

    inline int newnode() {
        t.push_back(neutral);
        Lc.push_back(-1);
        Rc.push_back(-1);
        lazy.push_back(0);
        replace.push_back(false);
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

    void push(int u, ll l, ll r) {
        if (replace[u]) {
            t[u] = lazy[u] * (r - l + 1);
            if (l != r) {
                lazy[le(u)] = lazy[u];
                lazy[ri(u)] = lazy[u];
                replace[le(u)] = replace[u];
                replace[ri(u)] = replace[u];
            }
        } else if (lazy[u] != 0) {
            t[u] += lazy[u] * (r - l + 1);
            if (l != r) {
                lazy[le(u)] += lazy[u];
                lazy[ri(u)] += lazy[u];
            }
        }
        replace[u] = false;
        lazy[u] = 0;
    }

    ll query(int u, ll l, ll r, ll L, ll R) {
        push(u, l, r);
        debug(u, l, r, L, R, t[u]);
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

    void update(int u, ll l, ll r, ll L, ll R, ll val, bool repl) {
        push(u, l, r);
        if (l > R || r < L) {
            return;
        }
        if (l >= L && r <= R) {
            lazy[u] = val;
            replace[u] = repl;
            push(u, l, r);
        } else {
            ll mid = l + (r - l) / 2;
            update(le(u), l, mid, L, R, val, repl);
            update(ri(u), mid + 1, r, L, R, val, repl);
            t[u] = merge(t[le(u)], t[ri(u)]);
        }
    }
    void update(ll l, ll r, ll val, bool repl = false) {
        update(0, MINL, MAXR, l, r, val, repl);
    }
};

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

    void push(int p, ll l, ll r) {
        if (replace[p]) {
            t[p] = lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[le(p)] = lazy[p];
                lazy[ri(p)] = lazy[p];
                replace[le(p)] = replace[p];
                replace[ri(p)] = replace[p];
            }
        } else if (lazy[p] != 0) {
            t[p] += lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[le(p)] += lazy[p];
                lazy[ri(p)] += lazy[p];
            }
        }
        replace[p] = false;
        lazy[p] = 0;
    }

    ll query(int p, ll l, ll r, ll L, ll R) {
        push(p, l, r);
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[p];
        }
        ll mid = l + (r - l) / 2;
        auto ql = query(le(p), l, mid, L, R);
        auto qr = query(ri(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r) { return query(0, MINL, MAXR, l, r); }

    void update(int p, ll l, ll r, ll L, ll R, ll val, bool repl) {
        push(p, l, r);
        if (l > R || r < L) {
            return;
        }
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            ll mid = l + (r - l) / 2;
            update(le(p), l, mid, L, R, val, repl);
            update(ri(p), mid + 1, r, L, R, val, repl);
            t[p] = merge(t[le(p)], t[ri(p)]);
        }
    }
    void update(ll l, ll r, ll val, bool repl = false) {
        update(0, MINL, MAXR, l, r, val, repl);
    }
};
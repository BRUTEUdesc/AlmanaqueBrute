template <ll MINL = (ll)-1e9 - 5, ll MAXR = (ll)1e9 + 5> struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    vector<ll> t;
    vector<int> Lc, Rc, roots;

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

    SegTree() { roots.push_back(newnode()); }

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
    ll query(ll l, ll r, int root = -1) {
        if (root == -1)
            root = roots.back();
        debug(root, MINL, MAXR, l, r);
        return query(root, MINL, MAXR, l, r);
    }

    void update(int u, int old, ll l, ll r, ll i, ll x) {
        if (l == r) {
            t[u] = x; // substitui
            // t[u] += x; // soma
            return;
        }
        ll mid = l + (r - l) / 2;
        if (i <= mid) {
            Rc[u] = ri(old);
            update(le(u), le(old), l, mid, i, x);
        } else {
            Lc[u] = le(old);
            update(ri(u), ri(old), mid + 1, r, i, x);
        }
        t[u] = merge(t[le(u)], t[ri(u)]);
    }
    int update(ll i, ll x, int root = -1) {
        int new_root = newnode();
        if (root == -1)
            root = roots.back();
        update(new_root, root, MINL, MAXR, i, x);
        roots.push_back(new_root);
        return roots.back();
    }
    int copy_root(int root) {
        int new_root = newnode();
        Lc[new_root] = le(root);
        Rc[new_root] = ri(root);
        roots.push_back(new_root);
        return roots.back();
    }
};
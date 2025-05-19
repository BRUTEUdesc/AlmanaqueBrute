const ll MINL = (ll)-1e9 - 5, MAXR = (ll)1e9 + 5;
struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;
    vector<ll> t;
    vector<int> Lc, Rc, roots;
    inline int newnode() {
        t.push_back(neutral);
        Lc.push_back(0);
        Rc.push_back(0);
        return (int)t.size() - 1;
    }
    inline int lc(int p, bool create = false) {
        if (create && Lc[p] == 0) Lc[p] = newnode();
        return Lc[p];
    }
    inline int rc(int p, bool create = false) {
        if (create && Rc[p] == 0) Rc[p] = newnode();
        return Rc[p];
    }
    SegTree() {
        roots.push_back(newnode());
        newnode();
    }
    ll query(int p, ll l, ll r, ll L, ll R) {
        if (p == 0 || l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        ll mid = l + (r - l) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r, int root = -1) {
        if (root == -1) root = roots.back();
        else root = roots[root];
        return query(root, MINL, MAXR, l, r);
    }
    void update(int p, int old, ll l, ll r, ll i, ll x, bool repl) {
        t[p] = t[old];
        if (l == r) {
            if (repl) t[p] = x; // substitui
            else t[p] += x;     // soma
            return;
        }
        ll mid = l + (r - l) / 2;
        if (i <= mid) {
            Rc[p] = rc(old);
            update(lc(p, true), lc(old), l, mid, i, x, repl);
        } else {
            Lc[p] = lc(old);
            update(rc(p, true), rc(old), mid + 1, r, i, x, repl);
        }
        t[p] = merge(t[lc(p)], t[rc(p)]);
    }
    int update(ll i, ll x, bool repl, int root = -1) {
        // root é qual versão da segtree vai ser atualizada,
        // -1 atualiza a ultima root
        int new_root = newnode();
        if (root == -1) root = roots.back();
        else root = roots[root];
        update(new_root, root, MINL, MAXR, i, x, repl);
        roots.push_back(new_root);
        return roots.back();
    }
    void sumUpdate(ll i, ll x, int root = -1) { update(i, x, 0, root); }
    void setUpdate(ll i, ll x, int root = -1) { update(i, x, 1, root); }
} seg;

const ll MINL = (ll)-1e9 - 5, MAXR = (ll)1e9 + 5;
struct SegTree {
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
    inline int lc(int p) {
        if (Lc[p] == -1) Lc[p] = newnode();
        return Lc[p];
    }
    inline int rc(int p) {
        if (Rc[p] == -1) Rc[p] = newnode();
        return Rc[p];
    }
    SegTree() { newnode(); }
    void push(int p, ll l, ll r) {
        if (replace[p]) {
            t[p] = lazy[p] * (r - l + 1); // alterar dependendo da operacao de merge
            if (l != r) {
                if(Lc[p] != -1)lazy[lc(p)] = lazy[p];
                if(Rc[p] != -1)lazy[rc(p)] = lazy[p];
                if(Lc[p] != -1)replace[lc(p)] = true;
                if(Rc[p] != -1)replace[rc(p)] = true;
            }
        } else if (lazy[p] != 0) {
            t[p] += lazy[p] * (r - l + 1); // alterar dependendo da operacao de merge
            if (l != r) {
                if(Lc[p] != -1)lazy[lc(p)] += lazy[p];
                if(Rc[p] != -1)lazy[rc(p)] += lazy[p];
            }
        }
        replace[p] = false;
        lazy[p] = 0;
    }
    ll query(int p, ll l, ll r, ll L, ll R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        ll mid = l + (r - l) / 2;
        auto ql = neutral;
        auto qr = neutral;
        if(Lc[p] != -1)ql = query(Lc[p], l, mid, L, R);
        if(Rc[p] != -1)qr = query(Rc[p], mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r) { return query(0, MINL, MAXR, l, r); }
    void update(int p, ll l, ll r, ll L, ll R, ll val, bool repl) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            ll mid = l + (r - l) / 2;
            if(!(l > R || mid < L))update(lc(p), l, mid, L, R, val, repl);
            if(!(mid+1 > R || r < L))update(rc(p), mid + 1, r, L, R, val, repl);
            t[p] = neutral;
            if(Lc[p] != -1)t[p] = merge(t[p], t[lc(p)]);
            if(Rc[p] != -1)t[p] = merge(t[p], t[rc(p)]);
        }
    }
    void update(ll l, ll r, ll val, bool repl) { update(0, MINL, MAXR, l, r, val, repl); }
    void sumUpdate(ll l, ll r, ll val) { update(l, r, val, 0); }
    void setUpdate(ll l, ll r, ll val) { update(l, r, val, 1); }
} seg;
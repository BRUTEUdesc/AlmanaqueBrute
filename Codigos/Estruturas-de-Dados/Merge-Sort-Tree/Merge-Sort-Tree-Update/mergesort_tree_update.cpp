template <typename T = int>
struct MergeSortTree {
    vector<ordered_set<pair<T, int>>> tree;
    vector<T> v;
    int n;
    int lc(int u) { return u << 1; }
    int rc(int u) { return u << 1 | 1; }
    void build(int u, int l, int r, const vector<T> &a) {
        if (l == r) {
            tree[u].insert({a[l], l});
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(u), l, mid, a);
        build(rc(u), mid + 1, r, a);
        for (auto x : tree[lc(u)]) tree[u].insert(x);
        for (auto x : tree[rc(u)]) tree[u].insert(x);
    }
    void build(const vector<T> &a) { // para construir com vector
        n = (int)a.size();
        v = a;
        tree.assign(4 * n, ordered_set<pair<T, int>>());
        build(1, 0, n - 1, a);
    }
    void build(T *bg, T *en) { // para construir com array de C
        build(vector<T>(bg, en));
    }
    int count(int u, int l, int r, int L, int R, int a, int b) {
        if (l > R || r < L || a > b) return 0;
        if (l >= L && r <= R) {
            int ub = (int)tree[u].order_of_key({b + 1, INT_MIN});
            int lb = (int)tree[u].order_of_key({a, INT_MIN});
            return ub - lb;
        }
        int mid = (l + r) >> 1;
        return count(lc(u), l, mid, L, R, a, b) + count(rc(u), mid + 1, r, L, R, a, b);
    }
    int count(int l, int r, int a, int b) { return count(1, 0, n - 1, l, r, a, b); }
    int less(int l, int r, int k) { return count(l, r, tree[1].begin()->first, k - 1); }
    void update(int u, int l, int r, int i, T x) {
        tree[u].erase({v[i], i});
        if (l == r) {
            v[i] = x;
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) update(lc(u), l, mid, i, x);
            else update(rc(u), mid + 1, r, i, x);
        }
        tree[u].insert({v[i], i});
    }
    void update(int i, T x) { update(1, 0, n - 1, i, x); }
};

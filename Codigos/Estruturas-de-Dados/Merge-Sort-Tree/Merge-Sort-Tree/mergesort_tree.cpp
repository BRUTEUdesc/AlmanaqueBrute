template <typename T = int>
struct MergeSortTree {
    vector<vector<T>> tree;
    int n;
    int lc(int u) { return u << 1; }
    int rc(int u) { return u << 1 | 1; }
    void build(int u, int l, int r, const vector<T> &a) {
        tree[u] = vector<T>(r - l + 1);
        if (l == r) {
            tree[u][0] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(u), l, mid, a);
        build(rc(u), mid + 1, r, a);
        merge(
            tree[lc(u)].begin(),
            tree[lc(u)].end(),
            tree[rc(u)].begin(),
            tree[rc(u)].end(),
            tree[u].begin()
        );
    }
    void build(const vector<T> &a) { // para construir com vector
        n = (int)a.size();
        tree.assign(4 * n, vector<T>());
        build(1, 0, n - 1, a);
    }
    void build(T *bg, T *en) { // para construir com array de C
        build(vector<T>(bg, en));
    }
    int count(int u, int l, int r, int L, int R, int a, int b) {
        if (l > R || r < L || a > b) return 0;
        if (l >= L && r <= R) {
            auto ub = upper_bound(tree[u].begin(), tree[u].end(), b);
            auto lb = upper_bound(tree[u].begin(), tree[u].end(), a - 1);
            return (int)(ub - lb);
        }
        int mid = (l + r) >> 1;
        return count(lc(u), l, mid, L, R, a, b) + count(rc(u), mid + 1, r, L, R, a, b);
    }
    int count(int l, int r, int a, int b) { return count(1, 0, n - 1, l, r, a, b); }
    int less(int l, int r, int k) { return count(l, r, tree[1][0], k - 1); }
    int kth(int l, int r, int k) {
        int L = 0, R = n - 1;
        int ans = -1;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (count(l, r, tree[1][0], tree[1][mid]) > k) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return tree[1][ans];
    }
};

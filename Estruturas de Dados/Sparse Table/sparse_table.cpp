struct SparseTable {
    int n, e;
    vector <vi> st;
    SparseTable(vi &v) : n(v.size()), e(floor(log2(n))) {
        st.assign(e+1, vi(n);
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]); // query de range
                // st[i][j] = min(st[i-1][j], st[i-1][st[i-1][j]]); // query de caminho
            }
        }
    }
    // O(NLog(N)) Query for non overlab friendly operations
    int logquery(int l, int r) {
        int res = 1123456789;
        for (int i = e; i >= 0; i--) {
            if ((1 << i) <= r-l+1) {
                res = min(res, st[i][l]);
                l += 1 << i;
            }
        }
        return res;
    }
    // O(1) Query for overlab friendly operations
    // ex: max(), min(), gcd(), f(x, y) = x
    int query(int l, int r) {
        int i = ilogb(r-l+1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

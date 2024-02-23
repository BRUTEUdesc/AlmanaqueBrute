struct SparseTable {
    int n, e;
    vector<vector<int>> st;
    SparseTable(vector<int> &v) : n(v.size()), e(floor(log2(n))) {
        st.assign(e + 1, vector<int>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = v[i];
        }
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        if (l > r)
            return 2e9;
        int i = ilogb(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

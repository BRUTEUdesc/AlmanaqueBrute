struct DisjointSparseTable {
    int n, LG;
    vector<vector<ll>> st;
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;
    void build(const vector<ll> &v) {
        int sz = (int)v.size();
        n = 1, LG = 1;
        while (n < sz) n <<= 1, LG++;
        st = vector<vector<ll>>(LG, vector<ll>(n));
        for (int i = 0; i < n; i++) st[0][i] = i < sz ? v[i] : neutral;
        for (int i = 1; i < LG - 1; i++) {
            for (int j = (1 << i); j < n; j += (1 << (i + 1))) {
                st[i][j] = st[0][j];
                st[i][j - 1] = st[0][j - 1];
                for (int k = 1; k < (1 << i); k++) {
                    st[i][j + k] = merge(st[i][j + k - 1], st[0][j + k]);
                    st[i][j - 1 - k] = merge(st[0][j - k - 1], st[i][j - k]);
                }
            }
        }
    }
    void build(ll *bg, ll *en) { build(vector<ll>(bg, en)); }
    ll query(int l, int r) {
        if (l == r) return st[0][l];
        int i = 31 - __builtin_clz(l ^ r);
        return merge(st[i][l], st[i][r]);
    }
} dst;
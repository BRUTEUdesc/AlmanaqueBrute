struct dst{
    const int neutral = 1;
    #define comp(a, b) (a | b)
    vector<vector<int>> t;
    dst(vi v){
        int n, k, sz = v.size();
        for(n = 1, k = 0; n < sz; n <<= 1, k++);
            t.assign(k, vector<int>(n));
        for(int i = 0; i < n; i++)
            t[0][i] = i < sz ? v[i] : neutral;
        for(int j = 0, len = 1; j <= k; j++, len <<= 1) {
            for(int s = len; s < n; s += (len << 1)) {
                t[j][s] = v[s]; t[j][s-1] = v[s-1];
                for(int i = 1; i < len; i++) {
                    t[j][s+i] = comp(t[j][s+i-1], v[s+i]);
                    t[j][s-1-i] = comp(v[s-1-i], t[j][s-i]);
                }
            }
        }
    }
    int query(int l, int r) {
        if(l == r) return t[0][r];
        int i = 31 - __builtin_clz(l^r);
        return comp(t[i][l], t[i][r]);
    }
};

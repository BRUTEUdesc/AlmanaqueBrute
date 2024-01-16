template<typename T> struct FenwickTree {
    vector<T> bit;
    FenwickTree(int n = 0) : bit(n, T()) {}
    FenwickTree(vector<T> &v) : bit(v.size(), T()) {
        int n = v.size();
        for (int i = 0; i < n; i++) bit[i] = v[i];
        for (int i = 0; i < n; i++) {
            int j = i | (i + 1);
            if (j < n) bit[j] = bit[j] + bit[i];
        }
    }
    T pref(int i) {
        T res = T();
        while (i >= 0) {
            res = res + bit[i];
            i &= i + 1;
            i--;
        }
        return res;
    }
    T query(int l, int r) {
        if (l == 0) return pref(r);
        return pref(r) - pref(l - 1);
    }
    void update(int i, T d) {
        while (i < (int)bit.size()) {
            bit[i] = bit[i] + d;
            i |= i + 1;
        }
    }
    void updateSet(int i, T d) {
        // funciona pra fenwick de soma
        T now = query(i, i);
        update(i, now * -1);
        update(i, d);
    }
};

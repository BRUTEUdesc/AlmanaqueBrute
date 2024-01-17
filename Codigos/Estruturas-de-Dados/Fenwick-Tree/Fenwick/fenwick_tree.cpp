template <typename T> struct FenwickTree {
    int n;
    vector<T> bit, arr;
    FenwickTree(int n = 0) : n(n), bit(n, T()), arr(n, T()) {}
    FenwickTree(vector<T> &v) : n(v.size()), bit(n, T()), arr(v) {
        for (int i = 0; i < n; i++) {
            bit[i] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            int j = i | (i + 1);
            if (j < n) {
                bit[j] = bit[j] + bit[i];
            }
        }
    }
    T pref(int x) {
        T res = T();
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            res = res + bit[i];
        }
        return res;
    }
    T query(int l, int r) {
        if (l == 0) {
            return pref(r);
        }
        return pref(r) - pref(l - 1);
    }
    void update(int x, T d) {
        for (int i = x; i < n; i = i | (i + 1)) {
            bit[i] = bit[i] + d;
        }
        arr[x] = arr[x] + d;
    }
    void updateSet(int i, T d) {
        // funciona pra fenwick de soma
        update(i, d - arr[i]);
        arr[i] = d;
    }
};

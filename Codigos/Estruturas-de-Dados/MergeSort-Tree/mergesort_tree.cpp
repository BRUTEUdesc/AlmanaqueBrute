namespace mergesort {
    const int MAX = 1e5 + 5;

    int n;
    vi mgtree[4 * MAX];

    int le(int n) {
        return 2 * n + 1;
    }
    int ri(int n) {
        return 2 * n + 2;
    }

    void build(int n, int esq, int dir, vi &v) {
        mgtree[n] = vi(dir - esq + 1, 0);
        if (esq == dir) {
            mgtree[n][0] = v[esq];
        } else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid, v);
            build(ri(n), mid + 1, dir, v);
            merge(mgtree[le(n)].begin(),
                  mgtree[le(n)].end(),
                  mgtree[ri(n)].begin(),
                  mgtree[ri(n)].end(),
                  mgtree[n].begin());
        }
    }
    void build(vi &v) {
        n = v.size();
        build(0, 0, n - 1, v);
    }

    int less(int n, int esq, int dir, int l, int r, int k) {
        if (esq > r || dir < l) {
            return 0;
        }
        if (l <= esq && dir <= r) {
            return lower_bound(mgtree[n].begin(), mgtree[n].end(), k) -
                   mgtree[n].begin();
        }
        int mid = (esq + dir) / 2;
        return less(le(n), esq, mid, l, r, k) +
               less(ri(n), mid + 1, dir, l, r, k);
    }
    int less(int l, int r, int k) {
        return less(0, 0, n - 1, l, r, k);
    }

    // vi debug_query(int n, int esq, int dir, int l, int r) {
    //     if (esq > r || dir < l) return vi();
    //     if (l <= esq && dir <= r) return mgtree[n];
    //     int mid = (esq + dir) / 2;
    //     auto vl = debug_query(le(n), esq, mid, l, r);
    //     auto vr = debug_query(ri(n), mid+1, dir, l, r);
    //     vi ans = vi(vl.size() + vr.size());
    //     merge(vl.begin(), vl.end(),
    //         vr.begin(), vr.end(),
    //         ans.begin());
    //     return ans;
    // }
    // vi debug_query(int l, int r) {return debug_query(0, 0, n-1, l, r);}
};

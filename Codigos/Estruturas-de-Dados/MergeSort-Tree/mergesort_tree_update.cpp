#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

namespace mergesort {
    typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
    const int MAX = 1e5 + 5;

    int n;
    ordered_set mgtree[4 * MAX];
    vi values;

    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }

    ordered_set join(ordered_set set_l, ordered_set set_r) {
        for (auto v : set_r) {
            set_l.insert(v);
        }
        return set_l;
    }

    void build(int n, int esq, int dir) {
        if (esq == dir) {
            mgtree[n].insert(ii(values[esq], esq));
        } else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid);
            build(ri(n), mid + 1, dir);
            mgtree[n] = join(mgtree[le(n)], mgtree[ri(n)]);
        }
    }
    void build(vi &v) {
        n = v.size();
        values = v;
        build(0, 0, n - 1);
    }

    int less(int n, int esq, int dir, int l, int r, int k) {
        if (esq > r || dir < l) {
            return 0;
        }
        if (l <= esq && dir <= r) {
            return mgtree[n].order_of_key({k, -1});
        }
        int mid = (esq + dir) / 2;
        return less(le(n), esq, mid, l, r, k) + less(ri(n), mid + 1, dir, l, r, k);
    }
    int less(int l, int r, int k) { return less(0, 0, n - 1, l, r, k); }

    void update(int n, int esq, int dir, int x, int v) {
        if (esq > x || dir < x) {
            return;
        }
        if (esq == dir) {
            mgtree[n].clear(), mgtree[n].insert(ii(v, x));
        } else {
            int mid = (esq + dir) / 2;
            if (x <= mid) {
                update(le(n), esq, mid, x, v);
            } else {
                update(ri(n), mid + 1, dir, x, v);
            }
            mgtree[n].erase(ii(values[x], x));
            mgtree[n].insert(ii(v, x));
        }
    }
    void update(int x, int v) {
        update(0, 0, n - 1, x, v);
        values[x] = v;
    }

    // ordered_set debug_query(int n, int esq, int
    // dir, int l, int r) {
    //     if (esq > r || dir < l) return
    //     ordered_set(); if (l <= esq && dir <=
    //     r) return mgtree[n]; int mid = (esq +
    //     dir) / 2; return
    //     join(debug_query(le(n), esq, mid, l,
    //     r), debug_query(ri(n), mid+1, dir, l,
    //     r));
    // }
    // ordered_set debug_query(int l, int r)
    // {return debug_query(0, 0, n-1, l, r);}

    // int greater(int n, int esq, int dir, int l,
    // int r, int k) {
    //     if (esq > r || dir < l) return 0;
    //     if (l <= esq && dir <= r) return
    //     (r-l+1) - mgtree[n].order_of_key({k,
    //     1e8}); int mid = (esq + dir) / 2;
    //     return greater(le(n), esq, mid, l, r,
    //     k) + greater(ri(n), mid+1, dir, l, r,
    //     k);
    // }
    // int greater(int l, int r, int k) {return
    // greater(0, 0, n-1, l, r, k);}
};

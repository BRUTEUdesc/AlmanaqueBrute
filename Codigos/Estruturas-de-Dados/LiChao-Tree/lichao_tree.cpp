typedef long long ll;

const ll MAXN = 2e5 + 5, INF = 1e18 + 9, MAXR = 1e18;

struct Line {
    ll a, b = -INF;
    __int128 operator()(ll x) { return (__int128)a * x + b; }
} tree[4 * MAXN];
int idx = 0, L[4 * MAXN], R[4 * MAXN];

int le(int n) {
    if (!L[n]) {
        L[n] = ++idx;
    }
    return L[n];
}
int ri(int n) {
    if (!R[n]) {
        R[n] = ++idx;
    }
    return R[n];
}

void insert(Line line, int n = 0, ll l = -MAXR, ll r = MAXR) {
    ll mid = (l + r) / 2;
    bool bl = line(l) < tree[n](l);
    bool bm = line(mid) < tree[n](mid);
    if (!bm) {
        swap(tree[n], line);
    }
    if (l == r) {
        return;
    }
    if (bl != bm) {
        insert(line, le(n), l, mid);
    } else {
        insert(line, ri(n), mid + 1, r);
    }
}

__int128 query(int x, int n = 0, ll l = -MAXR, ll r = MAXR) {
    if (l == r) {
        return tree[n](x);
    }
    ll mid = (l + r) / 2;
    if (x < mid) {
        return max(tree[n](x), query(x, le(n), l, mid));
    } else {
        return max(tree[n](x), query(x, ri(n), mid + 1, r));
    }
}

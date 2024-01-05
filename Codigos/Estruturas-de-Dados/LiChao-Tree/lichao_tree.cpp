typedef long long ll;

const ll MAXN = 1e5 + 5, INF = 1e18 + 9;

struct Line {
    ll a, b = -INF;
    ll operator()(ll x) {
        return a * x + b;
    }
} tree[4 * MAXN];

int le(int n) {
    return 2 * n + 1;
}
int ri(int n) {
    return 2 * n +2;
}

void insert(Line line, int n = 0, int l = 0, int r = MAXN) {
    int mid = (l + r) / 2;
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

ll query(int x, int n = 0, int l = 0, int r = MAXN) {
    if (l == r) {
        return tree[n](x);
    }
    int mid = (l + r) / 2;
    if (x < mid) {
        return max(tree[n](x), query(x, le(n), l, mid));
    } else {
        return max(tree[n](x), query(x, ri(n), mid + 1, r));
    }
}

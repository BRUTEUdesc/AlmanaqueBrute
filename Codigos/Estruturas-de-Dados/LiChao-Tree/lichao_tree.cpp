template <ll MINL = ll(-1e9 - 5), ll MAXR = ll(1e9 + 5)>
struct LichaoTree {
    const ll INF = ll(2e18) + 10;
    struct Line {
        ll a, b;
        Line(ll a_ = 0, ll b_ = -INF) : a(a_), b(b_) {}
        ll operator()(ll x) { return a * x + b; }
    };
    vector<Line> tree;
    vector<int> L, R;

    int newnode() {
        tree.push_back(Line());
        L.push_back(-1);
        R.push_back(-1);
        return int(tree.size()) - 1;
    }

    LichaoTree() { newnode(); }

    int le(int u) {
        if (L[u] == -1) L[u] = newnode();
        return L[u];
    }

    int ri(int u) {
        if (R[u] == -1) R[u] = newnode();
        return R[u];
    }

    void insert(Line line, int n = 0, ll l = MINL, ll r = MAXR) {
        ll mid = (l + r) / 2;
        bool bl = line(l) > tree[n](l);
        bool bm = line(mid) > tree[n](mid);
        bool br = line(r) > tree[n](r);
        if (bm) swap(tree[n], line);
        if (line.b == -INF) return;
        if (bl != bm) insert(line, le(n), l, mid - 1);
        else if (br != bm) insert(line, ri(n), mid + 1, r);
    }

    ll query(int x, int n = 0, ll l = MINL, ll r = MAXR) {
        if (tree[n](x) == -INF || (l > r)) return -INF;
        if (l == r) return tree[n](x);
        ll mid = (l + r) / 2;
        if (x < mid) return max(tree[n](x), query(x, le(n), l, mid - 1));
        else return max(tree[n](x), query(x, ri(n), mid + 1, r));
    }
};

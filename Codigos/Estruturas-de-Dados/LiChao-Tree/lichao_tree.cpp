const ll INF = ll(2e18) + 10;
struct Line {
    ll a, b;
    Line(ll a_ = 0, ll b_ = -INF) : a(a_), b(b_) { }
    ll operator()(ll x) { return a * x + b; }
};

template <ll MINL = ll(-1e9 - 5), ll MAXR = ll(1e9 + 5)>
struct LichaoTree {
    vector<Line> tree;
    vector<int> L, R;

    int newnode() {
        tree.push_back(Line());
        L.push_back(0);
        R.push_back(0);
        return int(tree.size()) - 1;
    }

    LichaoTree() {
        newnode();
        newnode();
    }

    int lc(int p, bool create = false) {
        if (create && L[p] == 0) L[p] = newnode();
        return L[p];
    }

    int rc(int p, bool create = false) {
        if (create && R[p] == 0) R[p] = newnode();
        return R[p];
    }

    void insert(Line line, int p = 1, ll l = MINL, ll r = MAXR) {
        if (p == 0) return;
        ll mid = l + (r - l) / 2;
        bool bl = line(l) > tree[p](l);
        bool bm = line(mid) > tree[p](mid);
        bool br = line(r) > tree[p](r);
        if (bm) swap(tree[p], line);
        if (line.b == -INF) return;
        if (bl != bm) insert(line, lc(p, true), l, mid - 1);
        else if (br != bm) insert(line, rc(p, true), mid + 1, r);
    }

    ll query(int x, int p = 1, ll l = MINL, ll r = MAXR) {
        if (p == 0 || tree[p](x) == -INF || (l > r)) return -INF;
        if (l == r) return tree[p](x);
        ll mid = l + (r - l) / 2;
        if (x < mid) return max(tree[p](x), query(x, lc(p), l, mid - 1));
        else return max(tree[p](x), query(x, rc(p), mid + 1, r));
    }
};

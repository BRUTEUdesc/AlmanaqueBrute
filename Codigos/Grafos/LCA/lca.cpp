const int N = 5e5 + 5;
int timer, tin[N];
vector<int> adj[N];
vector<pair<int, int>> prof;

struct SparseTable {
    int n, LG;
    using T = pair<int, int>;
    vector<vector<T>> st;
    T merge(T a, T b) { return min(a, b); }
    const T neutral = {INT_MAX, -1};
    void build(const vector<T> &v) {
        n = (int)v.size();
        LG = 32 - __builtin_clz(n);
        st = vector<vector<T>>(LG, vector<T>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = v[i];
        }
        for (int i = 0; i < LG - 1; i++) {
            for (int j = 0; j + (1 << i) < n; j++) {
                st[i + 1][j] = merge(st[i][j], st[i][j + (1 << i)]);
            }
        }
    }
    T query(int l, int r) {
        if (l > r)
            return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
} st_lca;

void et_dfs(int u, int p, int h) {
    tin[u] = timer++;
    prof.emplace_back(h, u);
    for (int v : adj[u]) {
        if (v != p) {
            et_dfs(v, u, h + 1);
            prof.emplace_back(h, u);
        }
    }
    timer++;
}

int lca(int u, int v) {
    int l = tin[u], r = tin[v];
    if (l > r) {
        swap(l, r);
    }
    return st_lca.query(l, r).second;
}

void build() {
    timer = 0;
    prof.clear();
    et_dfs(0, -1, 0);
    st_lca.build(prof);
}
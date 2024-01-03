#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define fi first
#define se second

typedef vector<int> vi;
typedef pair<int, int> ii;

vi tin, tout;
vector<vi> adj;
vector<ii> prof;
vector<vector<ii>> st;

int n, timer;

void SparseTable(vector<ii> &v) {
    int n = v.size();
    int e = floor(log2(n));
    st.assign(e + 1, vector<ii>(n));
    for (int i = 0; i < n; i++) { st[0][i] = v[i]; }
    for (int i = 1; i <= e; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) { st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); }
    }
}

void et_dfs(int u, int p, int h) {
    tin[u] = timer++;
    prof.emplace_back(h, u);
    for (int v : adj[u]) {
        if (v != p) {
            et_dfs(v, u, h + 1);
            prof.emplace_back(h, u);
        }
    }
    tout[u] = timer++;
}

void build(int root = 0) {
    tin.assign(n, 0);
    tout.assign(n, 0);
    prof.clear();
    timer = 0;
    et_dfs(root, root, 0);
    SparseTable(prof);
}

int lca(int u, int v) {
    int l = tout[u], r = tin[v];
    if (l > r) { swap(l, r); }
    int i = floor(log2(r - l + 1));
    return min(st[i][l], st[i][r - (1 << i) + 1]).se;
}

int main() {
    cin >> n;

    adj.assign(n, vi(0));

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    build();
}

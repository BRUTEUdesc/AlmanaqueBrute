const int N = 3e5 + 5;

int sz[N], par[N];
bool rem[N];
vector<int> dis[N];
vector<int> adj[N];

int dfs_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !rem[v]) {
            sz[u] += dfs_sz(v, u);
        }
    }
    return sz[u];
}

int centroid(int u, int p, int szn) {
    for (int v : adj[u]) {
        if (v != p && !rem[v] && sz[v] > szn / 2) {
            return centroid(v, u, szn);
        }
    }
    return u;
}

void dfs_dis(int u, int p, int d = 0) {
    dis[u].push_back(d);
    for (int v : adj[u]) {
        if (v != p && !rem[v]) {
            dfs_dis(v, u, d + 1);
        }
    }
}

void decomp(int u, int p) {
    int c = centroid(u, u, dfs_sz(u, u));

    rem[c] = true;
    par[c] = p;

    dfs_dis(c, c);

    // Faz algo na subárvore de c

    for (int v : adj[c]) {
        if (!rem[v]) {
            decomp(v, c);
        }
    }
}

void build(int n) {
    for (int i = 0; i < n; i++) {
        rem[i] = false;
        dis[i].clear();
    }
    decomp(0, -1);
    for (int i = 0; i < n; i++) {
        reverse(dis[i].begin(), dis[i].end());
    }
}
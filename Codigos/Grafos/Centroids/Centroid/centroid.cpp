const int N = 3e5 + 5;

int sz[N];
vector<int> adj[N];

void dfs_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

int centroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v != p && sz[v] > n / 2) {
            return centroid(v, u, n);
        }
    }
    return u;
}

pair<int, int> centroids(int u) {
    dfs_sz(u, u);
    int c = centroid(u, u, sz[u]);
    int c2 = -1;
    for (int v : adj[c]) {
        if (sz[u] == sz[v] * 2) {
            c2 = v;
        }
    }
    return {c, c2};
}
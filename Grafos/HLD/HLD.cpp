int n, t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
vector <vi> adj;

void dfs_sz(int u, int p=-1) {
    sz[u] = 1;
    for (int &v : adj[u]) if (v != p) {
        dfs_sz(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
    }
}
void dfs_hld(int u, int p=-1) {
    pos[u] = t++;
    for (int v : adj[u]) if (v != p) {
        pai[v] = u;
        head[v] = (v == adj[u][0])? head[u]:v;
        dfs_hld(v, u);
    }
}
void build(int root=0) {
    dfs_sz(root);
    t = 0;
    pai[root] = root;
    head[root] = root;
    dfs_hld(root);
}
int query(int a, int b) { // query max on path
    if (pos[a] > pos[b]) swap(a, b);
    if (head[a] == head[b]) return seg_query(0, 0, n-1, pos[a], pos[b]);
    else {
        int qb = seg_query(0, 0, n-1, pos[head[b]], pos[b]);
        int qa = query(a, pai[head[b]]);
        return max(qa, qb);
    }
}
void update(int a, int b, int k) { // sum k on path
    if (pos[a] > pos[b]) swap(a, b);
    if (head[a] == head[b]) seg_update(0, 0, n-1, pos[a], pos[b]);
    else {
        seg_update(0, 0, n-1, pos[head[b]], pos[b], k);
        update(a, pai[head[b]], k);
    }
}

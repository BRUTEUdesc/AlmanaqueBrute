int n, t, sz[MAX], pos[MAX], pai[MAX], head[MAX], v[MAX], tree[4*MAX], lazy[4*MAX];
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

int le(int n) {return 2*n+1;}
int ri(int n) {return 2*n+2;}

void build(int n, int esq, int dir) {
    if (esq == dir) tree[n] = v[esq];
    else {
        int mid = (esq + dir)/2;
        build(le(n), esq, mid);
        build(ri(n), mid+1, dir);
        tree[n] = max(tree[le(n)], tree[ri(n)]);
    }
}
void build(int root=0) {
    dfs_sz(root);
    t = 0;
    pai[root] = root;
    head[root] = root;
    dfs_hld(root);
    build(0, 0, n-1);
}

void push(int n, int esq, int dir) {
    tree[n] += lazy[n];
    if (esq != dir) {
        lazy[le(n)] += lazy[n];
        lazy[ri(n)] += lazy[n];
    }
    lazy[n] = 0;
}

// max on path
int query(int n, int esq, int dir, int l, int r) {
    push(n, esq, dir);
    if (esq > r || dir < l) return 0;
    if (l <= esq && dir <= r) return tree[n];
    int mid = (esq + dir) / 2;
    return max(query(le(n), esq, mid, l, r), query(ri(n), mid+1, dir, l, r));
}
int query(int a, int b) {
    if (pos[a] > pos[b]) swap(a, b);
    if (head[a] == head[b]) return query(0, 0, n-1, pos[a], pos[b]);
    else {
        int qb = query(0, 0, n-1, pos[head[b]], pos[b]);
        int qa = query(a, pai[head[b]]);
        return max(qa, qb);
    }
}

// change vertex u value to k
void point_update(int n, int esq, int dir, int x, int v) {
    push(n, esq, dir);
    if (esq == dir) tree[n] = v;
    else {
        int mid = (esq + dir) / 2;
        if (x <= mid) point_update(le(n), esq, mid, x, v);
        else point_update(ri(n), mid+1, dir, x, v);
        tree[n] = max(tree[le(n)], tree[ri(n)]);
    }
}
void point_update(int u, int k) {
    point_update(0, 0, n-1, pos[u], k);
}

// sum k on path
void update(int n, int esq, int dir, int l, int r, int v) {
    push(n, esq, dir);
    if (esq > r || dir < l) return;
    if (l <= esq && dir <= r) {
        lazy[n] += k;
        push(n, esq, dir);
        return;
    }
    int mid = (esq + dir)/2;
    update(le(n), esq, mid, l, r, v);
    update(ri(n), mid+1, dir, l, r, v);
    tree[n] = max(tree[le(n)], tree[ri(n)]);
}
void update(int a, int b, int k) {
    if (pos[a] > pos[b]) swap(a, b);
    if (head[a] == head[b]) update(0, 0, n-1, pos[a], pos[b]);
    else {
        update(0, 0, n-1, pos[head[b]], pos[b], k);
        update(a, pai[head[b]], k);
    }
}

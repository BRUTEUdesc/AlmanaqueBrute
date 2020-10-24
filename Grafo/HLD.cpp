#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int n;
vector <vi> adj;
vi sz, pos, pai, head, tree, lazy;

void dfs_sz(int n = 0) {
    sz[n] = 0;
    int aux = 1;
    for (int &i : adj[n]) {
        if (sz[i] == -1) {
            dfs_sz(i);
            aux += sz[i];
        }
        if (sz[i] > sz[adj[n][0]]) swap(i, adj[n][0]);
    }
    sz[n] = aux;
}

int t = 0;
void dfs_hld(int n = 0) {
    pos[n] = t++;
    for (auto i : adj[n]) {
        if (pos[i] == -1) {
            pai[i] = n;
            head[i] = (i == adj[n][0])? head[n]:i;
            dfs_hld(i);
        }
    }
}

int le(int n) {return 2*n+1;}
int ri(int n) {return 2*n+2;}

void push(int n, int esq, int dir) {
    tree[n] += lazy[n] * (dir - esq + 1);
    if (esq != dir) {
        lazy[le(n)] += lazy[n];
        lazy[ri(n)] += lazy[n];
    }
    lazy[n] = 0;
}

int query(int n, int esq, int dir, int l, int r) {
    push(n, esq, dir);
    if (esq > r || dir < l) return 0;
    if (l <= esq && dir <= r) return tree[n];
    int mid = (esq + dir) / 2;
    return query(le(n), esq, mid, l, r)
           + query(ri(n), mid+1, dir, l, r);
}
int query(int a, int b) {
    if (pos[a] > pos[b]) swap(a, b);
    if (head[a] == head[b]) return query(0, 0, n-1, pos[a], pos[b]);
    else {
        int qb = query(0, 0, n-1, pos[head[b]], pos[b]);
        int qa = query(a, pai[head[b]]);
        return qa + qb;
    }
}

void update(int n, int esq, int dir, int l, int r, int v) {
    push(n, esq, dir);
    if (esq > r || dir < l) return;
    if (l <= esq && dir <= r) {
        tree[n] += v * (dir - esq + 1);
        if (esq != dir) {
            lazy[le(n)] += v;
            lazy[ri(n)] += v;
        }
    } else {
        int mid = (esq + dir) / 2;
        update(le(n), esq, mid, l, r, v);
        update(ri(n), mid+1, dir, l, r, v);
        tree[n] = tree[le(n)] + tree[ri(n)];
    }
}
void update(int a, int b, int v) {
    if (pos[a] > pos[b]) swap(a, b);
    if (head[a] == head[b]) update(0, 0, n-1, pos[a], pos[b], v);
    else {
        update(0, 0, n-1, pos[head[b]], pos[b], v);
        update(a, pai[head[b]], v);
    }
}

int main() {
    cin >> n;

    sz.assign(n, -1);
    pos.assign(n, -1);
    pai.assign(n, 0);
    head.assign(n, 0);
    tree.assign(4*n, 0);
    lazy.assign(4*n, 0);

    adj.assign(n, vi(0));
    // ler lista de adj aqui

    dfs_sz();
    dfs_hld();
}

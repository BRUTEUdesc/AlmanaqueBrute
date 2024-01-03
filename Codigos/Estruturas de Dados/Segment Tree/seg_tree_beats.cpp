#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

struct Node {
    int m1 = INF, m2 = INF, cont = 0, lazy = 0;
    ll soma = 0;

    void set(int v) {
        m1 = v;
        cont = 1;
        soma = v;
    }

    void merge(Node a, Node b) {
        m1 = min(a.m1, b.m1);
        m2 = INF;
        if (a.m1 != b.m1) { m2 = min(m2, max(a.m1, b.m1)); }
        if (a.m2 != m1) { m2 = min(m2, a.m2); }
        if (b.m2 != m1) { m2 = min(m2, b.m2); }
        cont = (a.m1 == m1 ? a.cont : 0) + (b.m1 == m1 ? b.cont : 0);
        soma = a.soma + b.soma;
    }

    void print() { printf("%d %d %d %lld %d\n", m1, m2, cont, soma, lazy); }
};

int n, q;
vector<Node> tree;

int le(int n) { return 2 * n + 1; }
int ri(int n) { return 2 * n + 2; }

void push(int n, int esq, int dir) {
    if (tree[n].lazy <= tree[n].m1) { return; }
    tree[n].soma += (ll)abs(tree[n].m1 - tree[n].lazy) * tree[n].cont;
    tree[n].m1 = tree[n].lazy;
    if (esq != dir) {
        tree[le(n)].lazy = max(tree[le(n)].lazy, tree[n].lazy);
        tree[ri(n)].lazy = max(tree[ri(n)].lazy, tree[n].lazy);
    }
    tree[n].lazy = 0;
}

void build(int n, int esq, int dir, vector<int> &v) {
    if (esq == dir) {
        tree[n].set(v[esq]);
    } else {
        int mid = (esq + dir) / 2;
        build(le(n), esq, mid, v);
        build(ri(n), mid + 1, dir, v);
        tree[n].merge(tree[le(n)], tree[ri(n)]);
    }
}
void build(vector<int> &v) { build(0, 0, n - 1, v); }

// ai = max(ai, mi) em [l, r]
void update(int n, int esq, int dir, int l, int r, int mi) {
    push(n, esq, dir);
    if (esq > r || dir < l || mi <= tree[n].m1) { return; }
    if (l <= esq && dir <= r && mi < tree[n].m2) {
        tree[n].lazy = mi;
        push(n, esq, dir);
    } else {
        int mid = (esq + dir) / 2;
        update(le(n), esq, mid, l, r, mi);
        update(ri(n), mid + 1, dir, l, r, mi);
        tree[n].merge(tree[le(n)], tree[ri(n)]);
    }
}
void update(int l, int r, int mi) { update(0, 0, n - 1, l, r, mi); }

// soma de [l, r]
int query(int n, int esq, int dir, int l, int r) {
    push(n, esq, dir);
    if (esq > r || dir < l) { return 0; }
    if (l <= esq && dir <= r) { return tree[n].soma; }
    int mid = (esq + dir) / 2;
    return query(le(n), esq, mid, l, r) + query(ri(n), mid + 1, dir, l, r);
}
int query(int l, int r) { return query(0, 0, n - 1, l, r); }

int main() {
    cin >> n;
    tree.assign(4 * n, Node());
}

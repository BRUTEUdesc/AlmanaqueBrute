#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

vi tree, lazy;

int le(int n) {return 2*n;}
int ri(int n) {return 2*n+1;}

void push(int n, int esq, int dir) {
    tree[n] += lazy[n] * (dir - esq + 1);
    if (esq != dir) {
        lazy[le(n)] += lazy[n];
        lazy[ri(n)] += lazy[n];
    }
    lazy[n] = 0;
}

void build(int n, int esq, int dir, vi &v) {
    if (esq == dir) tree[n] = v[esq];
    else {
        int mid = (esq + dir) / 2;
        build(le(n), esq, mid, v);
        build(ri(n), mid+1, dir, v);
        tree[n] = tree[le(n)] + tree[ri(n)];
    }
}

int query(int n, int esq, int dir, int l, int r) {
    push(n, esq, dir);
    if (esq > r || dir < l) return 0;
    if (l <= esq && dir <= r) return tree[n];
    int mid = (esq + dir) / 2;
    return query(le(n), esq, mid, l, r)
           + query(ri(n), mid+1, dir, l, r);
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

int main() {
    int n;
    cin >> n;
    tree.assign(4*n, 0);
    lazy.assign(4*n, 0);
}
#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

const int MAX = 1e5+5;

int n, tree[4*MAX], lazy[4*MAX];

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

void build(int n, int esq, int dir, vi &v) {
    if (esq == dir) tree[n] = v[esq];
    else {
        int mid = (esq + dir) / 2;
        build(le(n), esq, mid, v);
        build(ri(n), mid+1, dir, v);
        tree[n] = tree[le(n)] + tree[ri(n)];
    }
}
void build(vi &v) {build(0, 0, n-1, v);}

int query(int n, int esq, int dir, int l, int r) {
    push(n, esq, dir);
    if (esq > r || dir < l) return 0;
    if (l <= esq && dir <= r) return tree[n];
    int mid = (esq + dir) / 2;
    return query(le(n), esq, mid, l, r)
           + query(ri(n), mid+1, dir, l, r);
}
int query(int l, int r) {return query(0, 0, n-1, l, r);}

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
void update(int l, int r, int v) {update(0, 0, n-1, l, r, v);}

int main() {
    cin >> n;
}

#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int n;
vi tree;

int le(int n) {return 2*n;}
int ri(int n) {return 2*n+1;}

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
    if (esq > r || dir < l) return 0;
    if (l <= esq && dir <= r) return tree[n];
    int mid = (esq + dir) / 2;
    return query(le(n), esq, mid, l, r)
           + query(ri(n), mid+1, dir, l, r);
}
int query(int l, int r) {return query(0, 0, n-1, l, r);}

void update(int n, int esq, int dir, int x, int v) {
    if (esq > x || dir < x) return;
    if (esq == dir) tree[n] = v;
    else {
        int mid = (esq + dir) / 2;
        if (x <= mid)
            update(le(n), esq, mid, x, v);
        else
            update(ri(n), mid+1, dir, x, v);
        tree[n] = tree[le(n)] + tree[ri(n)];
    }
}
void update(int x, int v) {update(0, 0, n-1, x, v);}

int main() {
    cin >> n;
    tree.assign(4*n, 0);
}
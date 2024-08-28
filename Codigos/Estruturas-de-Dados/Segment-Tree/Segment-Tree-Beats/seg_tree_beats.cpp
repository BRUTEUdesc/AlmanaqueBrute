#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

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
        if (a.m1 != b.m1) m2 = min(m2, max(a.m1, b.m1));
        if (a.m2 != m1) m2 = min(m2, a.m2);
        if (b.m2 != m1) m2 = min(m2, b.m2);
        cont = (a.m1 == m1 ? a.cont : 0) + (b.m1 == m1 ? b.cont : 0);
        soma = a.soma + b.soma;
    }
};

struct SegTreeBeats {
    int n, q;
    vector<Node> t;
    inline int lc(int n) { return 2 * n + 1; }
    inline int rc(int n) { return 2 * n + 2; }
    void push(int n, int esq, int dir) {
        if (t[n].lazy <= t[n].m1) return;
        t[n].soma += (ll)abs(t[n].m1 - t[n].lazy) * t[n].cont;
        t[n].m1 = t[n].lazy;
        if (esq != dir) {
            t[lc(n)].lazy = max(t[lc(n)].lazy, t[n].lazy);
            t[rc(n)].lazy = max(t[rc(n)].lazy, t[n].lazy);
        }
        t[n].lazy = 0;
    }
    void build(int n, int esq, int dir, const vector<ll> &v) {
        if (esq == dir) {
            t[n].set(v[esq]);
        } else {
            int mid = (esq + dir) / 2;
            build(lc(n), esq, mid, v);
            build(rc(n), mid + 1, dir, v);
            t[n].merge(t[lc(n)], t[rc(n)]);
        }
    }
    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 4, Node());
    }
    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, Node());
        build(0, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }
    // ai = max(ai, mi) em [l, r]
    void update(int n, int esq, int dir, int l, int r, int mi) {
        push(n, esq, dir);
        if (esq > r || dir < l || mi <= t[n].m1) return;
        if (l <= esq && dir <= r && mi < t[n].m2) {
            t[n].lazy = mi;
            push(n, esq, dir);
        } else {
            int mid = (esq + dir) / 2;
            update(lc(n), esq, mid, l, r, mi);
            update(rc(n), mid + 1, dir, l, r, mi);
            t[n].merge(t[lc(n)], t[rc(n)]);
        }
    }
    void update(int l, int r, int mi) { update(0, 0, n - 1, l, r, mi); }
    // soma de [l, r]
    ll query(int n, int esq, int dir, int l, int r) {
        push(n, esq, dir);
        if (esq > r || dir < l) return 0;
        if (l <= esq && dir <= r) return t[n].soma;
        int mid = (esq + dir) / 2;
        return query(lc(n), esq, mid, l, r) + query(rc(n), mid + 1, dir, l, r);
    }
    ll query(int l, int r) { return query(0, 0, n - 1, l, r); }
} seg;

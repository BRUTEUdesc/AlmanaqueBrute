struct DSU {
    vector <int> pa, sz;
    DSU(int n){
        sz.assign(n+5, 1);
        for (int i = 0; i < n+5; i++) pa.push_back(i);
    }
    int root(int a){ return pa[a] = (a == pa[a]? a: root(pa[a]));}
    bool find(int a, int b){ return root(a) == root(b);}
    void uni(int a, int  b){
        int ra = root(a), rb = root(b);
        if (ra == rb) return;
        if (sz[ra] > sz[rb]) swap(ra, rb);
        pa[ra] = rb;
        sz[rb] += sz[ra];
    }
};

// foi o machado quem fez
struct DSU {
    vector <int> pai, tam;

    DSU(int n) {
        pai.assign(n, 0);
        for (int i = 0; i < n; i++) pai[i] = i;
        tam.assign(n, 1);
    }

    int root(int n) {
        if (n != pai[n]) pai[n] = root(pai[n]);
        return pai[n];
    }

    bool find(int a, int b) {return root(a) == root(b);}

    void uni(int a, int  b) {
        int ra = root(a), rb = root(b);
        if (ra == rb) return;
        if (tam[ra] > tam[rb]) swap(ra, rb);
        pai[ra] = rb;
        tam[rb] += tam[ra];
    }
};

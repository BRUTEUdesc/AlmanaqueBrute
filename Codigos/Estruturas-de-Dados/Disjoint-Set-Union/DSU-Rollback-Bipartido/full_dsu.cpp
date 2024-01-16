struct Full_DSU {
    vector<int> par, sz, c, bip;
    int number_of_sets, all_bipartite;
    stack<stack<pair<int &, int>>> changes;
    Full_DSU(int n = 0)
        : par(n), sz(n, 1), c(n), bip(n, 1), number_of_sets(n), all_bipartite(1) {
        iota(par.begin(), par.end(), 0);
        changes.emplace();
    }
    int find(int a) {
        return a == par[a] ? a : find(par[a]);
    }
    int color(int a) {
        return a == par[a] ? c[a] : c[a] ^ color(par[a]);
    }
    bool bipartite(int a) {
        return bip[find(a)];
    }
    void checkpoint() {
        changes.emplace();
    }
    void save(int &a) {
        changes.top().emplace(a, a);
    }
    bool unite(int a, int b) {
        bool equal_color = color(a) == color(b);
        a = find(a), b = find(b);
        if (a == b) {
            if (equal_color) {
                save(bip[a]);
                save(all_bipartite);
                bip[a] = 0;
                all_bipartite = 0;
            }
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        save(number_of_sets);
        save(par[b]);
        save(sz[a]);
        save(c[b]);
        save(bip[a]);
        save(all_bipartite);
        number_of_sets--;
        par[b] = a;
        sz[a] += sz[b];
        if (equal_color) {
            c[b] = 1;
        }
        bip[a] &= bip[b];
        all_bipartite &= bip[a];
        return true;
    }
    void rollback() {
        while (changes.top().size()) {
            auto [a, b] = changes.top().top();
            a = b;
            changes.top().pop();
        }
        changes.pop();
    }
};
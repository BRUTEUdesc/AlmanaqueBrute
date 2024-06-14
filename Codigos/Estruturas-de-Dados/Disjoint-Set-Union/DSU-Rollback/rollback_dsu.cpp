struct Rollback_DSU {
    vector<int> par, sz;
    int number_of_sets;
    stack<stack<pair<int &, int>>> changes;
    Rollback_DSU(int n = 0) : par(n), sz(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
        changes.emplace();
    }
    int find(int a) { return a == par[a] ? a : find(par[a]); }
    void checkpoint() { changes.emplace(); }
    void change(int &a, int b) {
        changes.top().emplace(a, a);
        a = b;
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        change(number_of_sets, number_of_sets - 1);
        change(par[b], a);
        change(sz[a], sz[a] + sz[b]);
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
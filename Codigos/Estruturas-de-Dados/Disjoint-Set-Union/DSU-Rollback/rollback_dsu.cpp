struct Rollback_DSU {
    vector<int> par, sz;
    stack<stack<pair<int &, int>>> changes;
    void build(int n) {
        par.assign(n, 0);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
        while (changes.size()) {
            changes.pop();
        }
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
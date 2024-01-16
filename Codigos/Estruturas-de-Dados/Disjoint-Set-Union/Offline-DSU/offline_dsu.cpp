struct Offline_DSU : Full_DSU {
    int time;
    Offline_DSU(int n = 0) : Full_DSU(n), time(0) {}
    struct query {
        int type, a, b;
    };
    vector<query> queries;
    void askConnect(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        queries.push_back({0, a, b});
        time++;
    }
    void askBipartite(int a) {
        queries.push_back({1, a, -1});
        time++;
    }
    void askAllBipartite() {
        queries.push_back({2, -1, -1});
        time++;
    }
    void addEdge(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        queries.push_back({3, a, b});
        time++;
    }
    void removeEdge(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        queries.push_back({4, a, b});
        time++;
    }
    vector<vector<pair<int, int>>> lazy;
    void update(int l, int r, pair<int, int> edge, int u, int L, int R) {
        if (R < l || L > r) {
            return;
        }
        if (L >= l && R <= r) {
            lazy[u].push_back(edge);
            return;
        }
        int mid = (L + R) / 2;
        update(l, r, edge, 2 * u, L, mid);
        update(l, r, edge, 2 * u + 1, mid + 1, R);
    }
    void dfs(int u, int L, int R, vector<int> &ans) {
        if (L > R) {
            return;
        }
        checkpoint();
        for (auto [a, b] : lazy[u]) {
            unite(a, b);
        }
        if (L == R) {
            auto [type, a, b] = queries[L];
            if (type == 0) {
                ans.push_back(find(a) == find(b));
            } else if (type == 1) {
                ans.push_back(bipartite(a));
            } else if (type == 2) {
                ans.push_back(all_bipartite);
            }
        } else {
            int mid = (L + R) / 2;
            dfs(2 * u, L, mid, ans);
            dfs(2 * u + 1, mid + 1, R, ans);
        }
        rollback();
    }
    vector<int> solve() {
        lazy.assign(4 * time, {});
        map<pair<int, int>, int> edges;
        for (int i = 0; i < time; i++) {
            auto [type, a, b] = queries[i];
            if (type == 3) {
                edges[{a, b}] = i;
            } else if (type == 4) {
                update(edges[{a, b}], i, {a, b}, 1, 0, time - 1);
                edges.erase({a, b});
            }
        }
        for (auto [k, v] : edges) {
            update(v, time - 1, k, 1, 0, time - 1);
        }
        vector<int> ans;
        dfs(1, 0, time - 1, ans);
        return ans;
    }
};
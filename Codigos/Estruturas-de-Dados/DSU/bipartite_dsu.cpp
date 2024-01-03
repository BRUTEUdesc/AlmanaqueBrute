struct bipartite_dsu {
    vector<int> parent;
    vector<int> color;
    int size;
    bipartite_dsu(int n) {
        size = n;
        color.resize(n + 5, 0);
        for (int i = 0; i < n + 5; ++i) { parent.push_back(i); }
    }

    pair<int, bool> get(int a) {
        if (parent[a] == a) { return {a, 0}; }
        auto val = get(parent[a]);
        parent[a] = val.fi;
        color[a] = (color[a] + val.se) % 2;
        return {parent[a], color[a]};
    }

    bool same_color(int a, int b) {
        get(a);
        get(b);
        return color[a] == color[b];
    }
    bool same_group(int a, int b) {
        get(a);
        get(b);
        return parent[a] == parent[b];
    }
    bool possible_edge(int a, int b) { return !same_color(a, b) || !same_group(a, b); }

    void join(int a, int b) {
        auto val_a = get(a), val_b = get(b);
        parent[val_a.fi] = val_b.fi;
        color[val_a.fi] = (val_a.se + val_b.se + 1) % 2;
    }
};

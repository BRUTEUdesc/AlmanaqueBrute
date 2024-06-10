namespace aho {
    const int M = 3e5 + 1;
    const int K = 26;

    const char norm = 'a';
    inline int get(int c) { return c - norm; }

    int next[M][K], link[M], out_link[M], par[M], cur = 2;
    char pch[M];
    bool out[M];
    vector<int> output[M];

    int node(int p, char c) {
        link[cur] = out_link[cur] = 0;
        par[cur] = p;
        pch[cur] = c;
        return cur++;
    }

    int T = 0;

    int insert(const string &s) {
        int u = 1;
        for (int i = 0; i < (int)s.size(); i++) {
            auto v = next[u][get(s[i])];
            if (v == 0) next[u][get(s[i])] = v = node(u, s[i]);
            u = v;
        }
        out[u] = true;
        output[u].emplace_back(T);
        return T++;
    }

    int go(int u, char c);

    int get_link(int u) {
        if (link[u] == 0) link[u] = par[u] > 1 ? go(get_link(par[u]), pch[u]) : 1;
        return link[u];
    }

    int go(int u, char c) {
        if (next[u][get(c)] == 0) next[u][get(c)] = u > 1 ? go(get_link(u), c) : 1;
        return next[u][get(c)];
    }

    int exit(int u) {
        if (out_link[u] == 0) {
            int v = get_link(u);
            out_link[u] = (out[v] || v == 1) ? v : exit(v);
        }
        return out_link[u];
    }

    bool matched(int u) { return out[u] || exit(u) > 1; }

}
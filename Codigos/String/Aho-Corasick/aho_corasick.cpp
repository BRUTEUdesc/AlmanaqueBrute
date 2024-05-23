struct AC {
    const int K = 26;
    const char norm = 'a';
    inline int get(int c) { return c - norm; }

    vector<int> link, out_link, par;
    vector<char> pch;
    vector<vector<int>> next;
    vector<bool> out;
    vector<vector<int>> output;

    AC() { node(); }

    int node(int p = -1, char c = -1) {
        link.push_back(-1);
        out_link.push_back(-1);
        par.push_back(p);
        pch.push_back(c);
        next.push_back(vector<int>(K, -1));
        out.push_back(false);
        output.push_back(vector<int>());
        return (int)link.size() - 1;
    }

    int T = 0;

    int insert(const string &s) {
        int u = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            auto v = next[u][get(s[i])];
            if (v == -1) {
                next[u][get(s[i])] = v = node(u, s[i]);
            }
            u = v;
        }
        out[u] = true;
        output[u].emplace_back(T);
        return T++;
    }

    int get_link(int u) {
        if (link[u] == -1) {
            link[u] = par[u] > 0 ? go(get_link(par[u]), pch[u]) : 0;
        }
        return link[u];
    }

    int go(int u, char c) {
        if (next[u][get(c)] == -1) {
            next[u][get(c)] = u ? go(get_link(u), c) : 0;
        }
        return next[u][get(c)];
    }

    int exit(int u) {
        if (out_link[u] == -1) {
            int v = get_link(u);
            out_link[u] = (out[v] || !v) ? v : exit(v);
        }
        return out_link[u];
    }

    bool matched(int u) { return out[u] || exit(u) != 0; }

} aho;

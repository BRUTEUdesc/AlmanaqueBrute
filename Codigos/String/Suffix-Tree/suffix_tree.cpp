const int N = 5e5 + 5;
const int S = 2 * N;

struct SuffixTree {
    array<int, 26> to[S];
    int lnk[S], len[S], cnt[S], idx[S], where[S], suff[S];
    int last = 1, id = 2;
    ll distinct_substrings = 0;
    string s;

    const char norm = 'a';
    inline int get(char c) { return c - norm; }

    void insert(int i, char ch) {
        int cur = id++;
        int c = get(ch);
        len[cur] = len[last] + 1;
        where[idx[cur] = i] = cur;
        cnt[cur] = suff[cur] = 1;
        int p = last;
        while (p > 0 && !to[p][c]) {
            to[p][c] = cur;
            p = lnk[p];
        }
        if (p == 0) {
            lnk[cur] = 1;
        } else {
            int sp = to[p][c];
            if (len[p] + 1 == len[sp]) {
                lnk[cur] = sp;
            } else {
                int clone = id++;
                len[clone] = len[p] + 1;
                lnk[clone] = lnk[sp];
                idx[clone] = idx[sp];
                to[clone] = to[sp];
                while (p > 0 && to[p][c] == sp) {
                    to[p][c] = clone;
                    p = lnk[p];
                }
                lnk[sp] = lnk[cur] = clone;
            }
        }
        last = cur;
    }

    vector<int> adj[S];

    void dfs(int u) {
        sort(adj[u].begin(), adj[u].end(), [&](int v1, int v2) {
            // sorta os filhos de u por ordem lexicografica,
            // isso faz com que a ordem de dfs seja a ordem
            // lexicografica dos sufixos (e de qualquer substring na verdade)
            return s[idx[v1] + len[u]] < s[idx[v2] + len[u]];
        });
        for (int v : adj[u]) {
            dfs(v);
            cnt[u] += cnt[v];
        }
        distinct_substrings += len[u] - len[lnk[u]];
    }

    void set_string(const string &s2) {
        s = s2;
        int n = (int)s.size();
        for (int i = 0; i < id; i++) {
            to[i].fill(0);
            len[i] = lnk[i] = cnt[i] = 0;
        }
        id = 2;
        for (int i = n - 1; i >= 0; i--) insert(i, s[i]);
        for (int i = 2; i < id; i++) adj[lnk[i]].push_back(i);
        dfs(1);
    }

    int count_occurrences(const string &t) {
        int cur = 1, m = (int)t.size();
        for (int i = m - 1; i >= 0; i--) {
            int c = get(t[i]);
            if (!to[cur][c]) return 0;
            cur = to[cur][c];
        }
        return cnt[cur];
    }

    int longest_common_substring(const string &t) {
        int cur = 1, clen = 0, ans = 0, m = (int)t.size();
        for (int i = m - 1; i >= 0; i--) {
            int c = get(t[i]);
            while (cur > 0 && !to[cur][c]) {
                cur = lnk[cur];
                clen = len[cur];
            }
            if (to[cur][c]) {
                cur = to[cur][c];
                clen++;
            }
            ans = max(ans, clen);
            cur = max(cur, 1);
        }
        return ans;
    }

    string kth_substring(ll k) {
        // esse metodo retorna a k-esima menor substring lexicograficamente,
        // dentre todas as substrings distintas
        string res = "";
        function<bool(int)> dfs_kth = [&](int u) {
            int min_len = len[lnk[u]] + 1, max_len = len[u];
            int qnt = (max_len - min_len + 1);
            if (qnt < k) {
                k -= qnt;
            } else {
                res = s.substr(idx[u], min_len + k - 1);
                return true;
            }
            for (int v : adj[u])
                if (dfs_kth(v)) return true;
            return false;
        };
        dfs_kth(1);
        return res;
    }

    string kth_substring2(ll k) {
        // esse metodo retorna a k-esima menor substring lexicograficamente,
        // dentre todas as substrings nao necessariamente distintas
        string res = "";
        function<bool(int)> dfs_kth = [&](int u) {
            int min_len = len[lnk[u]] + 1, max_len = len[u];
            ll qnt = 1LL * (max_len - min_len + 1) * cnt[u];
            if (qnt < k) {
                k -= qnt;
            } else {
                res = s.substr(idx[u], min_len + (k - 1) / cnt[u]);
                return true;
            }
            for (int v : adj[u])
                if (dfs_kth(v)) return true;
            return false;
        };
        dfs_kth(1);
        return res;
    }

    int lcp(int i, int j) {
        // retorna o maior prefixo comum entre os sufixos s[i..n) e s[j..n)
        // tem que codar o lca aqui no automato
        return len[lca(where[i], where[j])];
    }
} st;
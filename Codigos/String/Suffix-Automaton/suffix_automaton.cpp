const int N = 5e5 + 5;
const int S = 2 * N;

struct SuffixAutomaton {
    array<int, 26> to[S];
    int lnk[S], len[S], cnt[S], idx[S], where[S];
    int last = 1, id = 2;
    ll distinct_substrings = 0;

    const char norm = 'a';
    inline int get(char c) { return c - norm; }

    void insert(int i, char ch) {
        int cur = id++;
        int c = get(ch);
        len[cur] = len[last] + 1;
        where[idx[cur] = i] = cur;
        cnt[cur] = 1;
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
        for (int v : adj[u]) {
            dfs(v);
            cnt[u] += cnt[v];
        }
        distinct_substrings += len[u] - len[lnk[u]];
    }

    void set_string(const string &s) {
        int n = (int)s.size();
        for (int i = 0; i < id; i++) {
            to[i].fill(0);
            len[i] = lnk[i] = cnt[i] = 0;
            adj[i].clear();
        }
        last = 1, id = 2, distinct_substrings = 0;
        for (int i = 0; i < n; i++) insert(i, s[i]);
        for (int i = 2; i < id; i++) adj[lnk[i]].push_back(i);
        dfs(1);
    }

    int count_occurrences(const string &t) {
        int cur = 1;
        for (char ch : t) {
            int c = get(ch);
            if (!to[cur][c]) return 0;
            cur = to[cur][c];
        }
        return cnt[cur];
    }

    int longest_common_substring(const string &t) {
        int cur = 1, clen = 0, ans = 0;
        for (char ch : t) {
            int c = get(ch);
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

    int lcs(int i, int j) {
        // retorna o maior sufixo comum entre os prefixos s[0..i] e s[0..j]
        // tem que codar o lca aqui no automato
        return len[lca(where[i], where[j])];
    }
} sam;

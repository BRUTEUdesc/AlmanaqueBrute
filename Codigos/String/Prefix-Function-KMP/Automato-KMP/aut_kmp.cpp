struct AutKMP {
    vector<vector<int>> nxt;
    void setString(string s) {
        s += '#';
        nxt.assign(s.size(), vector<int>(26));
        vector<int> p = pi(s);
        for (int c = 0; c < 26; c++) {
            nxt[0][c] = ('a' + c == s[0]);
        }
        for (int i = 1; i < int(s.size()); i++) {
            for (int c = 0; c < 26; c++) {
                nxt[i][c] = ('a' + c == s[i]) ? i + 1 : nxt[p[i - 1]][c];
            }
        }
    }
    vector<int> matching(string &s, string &t) {
        vector<int> match;
        for (int i = 0, j = 0; i < int(s.size()); i++) {
            j = nxt[j][s[i] - 'a'];
            if (j == int(t.size())) {
                match.push_back(i - j + 1);
            }
        }
        return match;
    }
} aut;

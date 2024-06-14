vector<int> pi(string &s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < int(s.size()); i++) {
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

vector<int> matching(string &s, string &t) { // s = texto, t = padrao
    vector<int> p = pi(t), match;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != t[j]) j = p[j - 1];
        if (s[i] == t[j]) j++;
        if (j == (int)t.size()) {
            match.push_back(i - j + 1);
            j = p[j - 1];
        }
    }
    return match;
}
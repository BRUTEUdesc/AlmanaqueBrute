vector<int> pi(string &s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

vector<int> kmp(string &s, string t) {
    t += '$';
    vector<int> p = pi(t), match;
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != t[j]) {
            j = p[j - 1];
        }
        if (s[i] == t[j]) {
            j++;
        }
        if (j == t.size() - 1) {
            match.push_back(i - j + 1);
        }
    }
    return match;
}

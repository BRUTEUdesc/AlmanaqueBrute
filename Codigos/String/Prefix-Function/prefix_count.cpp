vector<int> pi(string s) {
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

vector<int> prefixCount(string s) {
    vector<int> p = pi(s + '#');
    int n = s.size();
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cnt[p[i]]++;
    }
    for (int i = n - 1; i > 0; i--) {
        cnt[p[i - 1]] += cnt[i];
    }
    for (int i = 0; i <= n; i++) {
        cnt[i]++;
    }
    return cnt;
}
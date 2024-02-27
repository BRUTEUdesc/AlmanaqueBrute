vector<int> get_z(string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

vector<int> matching(string &s, string &t) { // s = texto, t = padrao
    string k = t + "$" + s;
    vector<int> z = get_z(k), match;
    int n = (int)t.size();
    for (int i = n + 1; i < (int)z.size(); i++) {
        if (z[i] == n) {
            match.push_back(i - n - 1);
        }
    }
    return match;
}
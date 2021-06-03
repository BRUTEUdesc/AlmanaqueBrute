struct manacher {
    long long n, count = 0;
    vector<int> d1, d2;
    long long solve(string &s) {
        n = s.size();
        solve_odd(s);
        solve_even(s);
        return count;
    }
    void solve_odd(string &s) {
        d1.resize(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1:min(d1[l+r-i], r-i+1);
            while (0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
            count += d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
    }
    void solve_even(string &s) {
        d2.resize(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0:min(d2[l+r-i+1], r-i+1);
            while (0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) k++;
            count += d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
    }
} mana;

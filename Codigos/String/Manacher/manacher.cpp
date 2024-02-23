struct Manacher {
    int n;
    ll count;
    vector<int> d1, d2, man;
    ll solve(const string &s) {
        n = int(s.size()), count = 0;
        solve_odd(s);
        solve_even(s);
        man.assign(2 * n - 1, 0);
        for (int i = 0; i < n; i++) {
            man[2 * i] = 2 * d1[i] - 1;
        }
        for (int i = 0; i < n - 1; i++) {
            man[2 * i + 1] = 2 * d2[i + 1];
        }
        return count;
    }
    void solve_odd(const string &s) {
        d1.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            count += d1[i] = k--;
            if (i + k > r) {
                l = i - k, r = i + k;
            }
        }
    }
    void solve_even(const string &s) {
        d2.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            count += d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1, r = i + k;
            }
        }
    }
    bool query(int i, int j) {
        assert(man.size());
        return man[i + j] >= j - i + 1;
    }
} mana;
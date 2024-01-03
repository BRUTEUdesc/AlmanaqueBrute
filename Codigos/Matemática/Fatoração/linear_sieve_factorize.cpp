namespace sieve {
    const int MAX = 1e4;
    int lp[MAX + 1], factor[MAX + 1];
    vector<int> pr;
    void build() {
        for (int i = 2; i <= MAX; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for (int j = 0; i * pr[j] <= MAX; ++j) {
                lp[i * pr[j]] = pr[j];
                factor[i * pr[j]] = i;
                if (pr[j] == lp[i]) { break; }
            }
        }
    }
    vector<int> factorize(int x) {
        if (x < 2) { return {}; }
        vector<int> v;
        for (int lpx = lp[x]; x >= lpx; x = factor[x]) { v.emplace_back(lp[x]); }
        return v;
    }
}

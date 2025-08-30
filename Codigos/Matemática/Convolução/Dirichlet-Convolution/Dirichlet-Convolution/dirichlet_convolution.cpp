template <typename T>
vector<T> dirichlet(const vector<int> &f, const vector<int> &g) {
    int n = int(max(f.size(), g.size()));
    vector<int> primes, spf(n, 1), cnt(n);
    vector<T> ans(n);
    ans[1] = (T)f[1] * g[1];
    for (int i = 2; i < n; i++) {
        if (spf[i] == 1) {
            spf[i] = i;
            primes.emplace_back(i);
            cnt[i] = i;
        }

        for (auto p : primes) {
            if (i * p >= n) break;
            spf[i * p] = p;
            if (spf[i] == p) {
                cnt[i * p] = cnt[i] * p;
                break;
            } else cnt[i * p] = p;
        }

        if (i == cnt[i])
            for (int j = 1; j <= cnt[i]; j *= spf[i]) ans[i] += (T)f[j] * g[cnt[i] / j];
        else ans[i] = (T)ans[i / cnt[i]] * ans[cnt[i]];
    }
    return ans;
}

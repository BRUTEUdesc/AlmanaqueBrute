struct DirichletConvolutionPrefix {
    ll N;
    int T;
    vector<mint> ans;

    DirichletConvolutionPrefix(ll n, int t) : N(n), T(t) { ans.assign(n / T + 1, 0); }

    vector<mint> solve(auto &&f, auto &&F, auto &&g, auto &&G) {
        if (N == 1) return vector<mint>(2, 1);
        ans.assign(N / T + 1, 0);
        for (ll i = 1; i <= N / T; i++) {
            ll now = N / i;
            mint f_sum = 0, g_sum = 0;
            for (int j = 1; (ll)j * j <= now; j++) {
                f_sum += f(j);
                g_sum += g(j);

                ans[i] += G(i * j) * f(j);
                ans[i] += F(i * j) * g(j);
            }
            ans[i] -= f_sum * g_sum;
        }
        return ans;
    }
};

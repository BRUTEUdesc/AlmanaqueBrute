struct DirichletInversePrefix {
    ll N;
    int T;
    vector<mint> init_pref, ans;
    vector<bool> vis;
    DirichletInversePrefix(ll n, int t, vector<mint> _init_pref)
        : N(n), T(t), init_pref(_init_pref) {
        vis.assign(n / T + 1, 0);
        ans.assign(n / T + 1, 0);
    }

    mint solve(ll n, ll floor_N, auto &&f, auto &&F, auto &&g) {
        if (n < int(init_pref.size())) {
            if (floor_N <= N / T) {
                vis[floor_N] = true;
                ans[floor_N] = init_pref[n];
            }
            return init_pref[n];
        }

        if (vis[floor_N]) return ans[floor_N];

        vis[floor_N] = true;
        ans[floor_N] = 1;
        int j = 1;
        for (; (ll)j * j <= n; j++) {
            if (j > 1) ans[floor_N] -= solve(n / j, floor_N * j, f, F, g) * f(j);
            { ans[floor_N] -= g(j) * F(n / j); }
        }
        --j;
        ans[floor_N] += init_pref[j] * F(j);
        return ans[floor_N];
    }

    vector<mint> solve(auto &&f, auto &&F, auto &&g) {
        if (N == 1) return vector<mint>(2, 1);
        vis.assign(N / T + 1, 0);
        ans.assign(N / T + 1, 0);
        for (int i = 1; i <= N / T; i++)
            if (!vis[i]) solve(N / i, i, f, F, g);
        return ans;
    }
};

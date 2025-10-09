vector<ll> get_divs(ll n) {
    vector<ll> divs;
    auto f = factorize(n); // qualquer código que fatore n
    sort(f.begin(), f.end());
    vector<pair<ll, int>> v;
    for (auto x : f)
        if (v.empty() || v.back().first != x) v.emplace_back(x, 1);
        else v.back().second += 1;
    auto dfs = [&](auto &&self, int i, ll cur) -> void {
        if (i == (int)v.size()) {
            divs.push_back(cur);
            return;
        }
        ll p = 1;
        for (int j = 0; j <= v[i].second; j++) {
            self(self, i + 1, cur * p);
            p *= v[i].first;
        }
    };
    dfs(dfs, 0, 1);
    sort(divs.begin(), divs.end());
    return divs;
}

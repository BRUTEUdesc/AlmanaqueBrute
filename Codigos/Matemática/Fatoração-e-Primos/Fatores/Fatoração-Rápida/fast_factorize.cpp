vector<ll> factorize(ll y) {
    vector<ll> f;
    if (y == 1) return f;
    auto dfs = [&](auto &&self, ll x) -> void {
        if (x == 1) return;
        if (x < Sieve::P) {
            auto fs = Sieve::factorize(x);
            f.insert(f.end(), fs.begin(), fs.end());
        } else if (MillerRabin::prime(x)) {
            f.push_back(x);
        } else {
            ll d = PollardRho::rho(x);
            self(self, d);
            self(self, x / d);
        }
    };
    dfs(dfs, y);
    sort(f.begin(), f.end());
    return f;
}

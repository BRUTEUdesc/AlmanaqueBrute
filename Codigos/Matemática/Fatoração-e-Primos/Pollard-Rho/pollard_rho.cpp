namespace PollardRho {
    ll mod_mul(ll a, ll b, ll m) { return (ll)((__int128)a * b % m); }
    ll rho(ll n) {
        auto f = [n](ll x) { return mod_mul(x, x, n) + 1; };
        ll x = 0, y = 0, t = 30, prd = 2, i = 1, q;
        while (t++ % 40 || gcd(prd, n) == 1) {
            if (x == y) x = ++i, y = f(x);
            if ((q = mod_mul(prd, max(x, y) - min(x, y), n))) prd = q;
            x = f(x), y = f(f(y));
        }
        return gcd(prd, n);
    }
}

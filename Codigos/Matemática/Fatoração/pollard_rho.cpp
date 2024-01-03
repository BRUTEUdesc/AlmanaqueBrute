long long mod_mul(long long a, long long b, long long m) { return (__int128)a * b % m; }

long long pollard_rho(long long n) {
    auto f = [n](long long x) {
        return mod_mul(x, x, n) + 1;
    };
    long long x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) { x = ++i, y = f(x); }
        if ((q = mod_mul(prd, max(x, y) - min(x, y), n))) { prd = q; }
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

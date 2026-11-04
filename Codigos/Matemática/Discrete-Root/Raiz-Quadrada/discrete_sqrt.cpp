using T = int;
T sqrt(mint a) {
    mint p = pow(a, (MOD - 1) / 2);
    if (p.v != 1) return p.v == 0 ? 0 : -1;
    /// check if 0 or no sqrt
    T s = MOD - 1;
    int r = 0;
    while (s % 2 == 0) s /= 2, ++r;
    mint n = 2;
    while (pow(n, (MOD - 1) / 2).v == 1) n = T(n) + 1;
    // n non-square, ord(g)=2^r, ord(b)=2^m, ord(g)=2^r, m<r
    for (mint x = pow(a, (s + 1) / 2), b = pow(a, s), g = pow(n, s);;) {
        if (b.v == 1) return min(x.v, MOD - x.v); // x^2=ab
        int m = 0;
        for (mint t = b; t.v != 1; t *= t) ++m;
        rep(r - m - 1) g *= g;         // ord(g)=2^{m+1}
        x *= g, g *= g, b *= g, r = m; // ord(g)=2^m, ord(b)<2^m
    }
}

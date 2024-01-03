
ll mod_mul(ll a, ll b, ll m) { return (__int128)a * b % m; }
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll g = ext_gcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

// convolution mod 1,097,572,091,361,755,137
poly big_convolution(poly a, poly b) {
    poly r0, r1, answer;
    r0 = convolution(a, b, 1);
    r1 = convolution(a, b, 2);

    ll s, r, p = mod[1] * mod[2];
    ext_gcd(mod[1], mod[2], r, s);

    answer.resize(r0.size());
    for (int i = 0; i < (int)answer.size(); i++) {
        answer[i] = (mod_mul((s * mod[2] + p) % p, r0[i], p) + mod_mul((r * mod[1] + p) % p, r1[i], p) + p) % p;
    }
    return answer;
}

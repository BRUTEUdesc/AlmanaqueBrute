ll exp_mod(ll base, ll exp) {
    ll b = base, res = 1;
    while (exp) {
        if (exp & 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        exp >>= 1;
    }
    return res;
}

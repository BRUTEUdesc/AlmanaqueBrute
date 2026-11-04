int inv(int a) {
    int x, y;
    int g = extended_gcd(a, MOD, x, y);
    if (g == 1) return (x % MOD + MOD) % MOD;
    return -1;
}

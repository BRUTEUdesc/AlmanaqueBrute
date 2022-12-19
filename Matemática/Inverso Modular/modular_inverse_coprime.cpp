int inv(int a) {
    int x = -1, y;
    int g = extended_gcd(a, MOD, x, y);
    if (g == 1) x = (x % m + m) % m;
    return x;
}

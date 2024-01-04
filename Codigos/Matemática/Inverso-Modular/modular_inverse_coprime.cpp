int inv(int a) {
    int x, y;
    int g = extended_gcd(a, MOD, x, y);
    if (g == 1) {
        return (x % m + m) % m;
    }
    return -1;
}

long long power(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool is_composite(long long n, long long a, long long d, int s) {
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool miller_rabin(long long n) {
    if (n < 2) return false;
    int r = 0;
    long long d = n - 1;
    while ((d & 1) == 0) d >>= 1, ++r;
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (is_composite(n, a, d, r)) return false;
    }
    return true;
}

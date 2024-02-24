ll power(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1) {
            result = (__int128)result * base % mod;
        }
        base = (__int128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool is_composite(ll n, ll a, ll d, int s) {
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }
    for (int r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1) {
            return false;
        }
    }
    return true;
}

bool miller_rabin(ll n) {
    if (n < 2) {
        return false;
    }
    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1, ++r;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
        if (n == a) {
            return true;
        }
        if (is_composite(n, a, d, r)) {
            return false;
        }
    }
    return true;
}

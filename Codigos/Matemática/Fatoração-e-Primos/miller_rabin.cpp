namespace MillerRabin {
    ll power(ll b, ll e, ll m) {
        ll r = 1;
        b = b % m;
        while (e > 0) {
            if (e & 1) r = (r * b) % m;
            b = (b * b) % m, e >>= 1;
        }
        return r;
    }
    inline bool composite(ll n, ll a, ll d, int s) {
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) return false;
        for (int r = 1; r < s; r++) {
            x = ((__int128)x * x) % n;
            if (x == n - 1) return false;
        }
        return true;
    }
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    bool prime(ll n) {
        if (n <= 2 || (n % 2 == 0)) return n == 2;
        ll d = n - 1, r = 0;
        while (d % 2 == 0) d /= 2, r++;
        for (int i = 0; i < 13 && primes[i] < n; i++) {
            if (n == primes[i]) return true;
            if (composite(n, primes[i], d, r)) return false;
        }
        return true;
    }
}

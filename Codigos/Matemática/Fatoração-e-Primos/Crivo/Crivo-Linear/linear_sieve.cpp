namespace Sieve {
    const int P = 5e6 + 1;
    vector<bool> is_prime(P, true);
    int lpf[P], primes[P], cnt = 0;
    void build() {
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i < P; i++) {
            if (is_prime[i]) {
                lpf[i] = i;
                primes[cnt++] = i;
            }
            for (int j = 0; j < cnt && i * primes[j] < P; j++) {
                is_prime[i * primes[j]] = 0;
                lpf[i * primes[j]] = primes[j];
                if (i % primes[j] == 0) break;
            }
        }
    }
    vector<int> factorize(int n) {
#warning lembra de chamar o build() antes de fatorar!
        vector<int> f;
        while (n > 1) {
            f.push_back(lpf[n]);
            n /= lpf[n];
        }
        return f;
    }
}

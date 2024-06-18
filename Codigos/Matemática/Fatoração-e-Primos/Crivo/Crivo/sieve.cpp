namespace Sieve {
    const int P = 5e6 + 1;
    vector<bool> is_prime(P, true);
    void build() {
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i < P; i++) {
            if (is_prime[i]) {
                for (int j = i + i; j < P; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    }
}
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 5, true);
    is_prime[0] = false;
    is_prime[1] = false;
    long long sq = sqrt(n + 5);
    for (long long i = 2; i <= sq; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

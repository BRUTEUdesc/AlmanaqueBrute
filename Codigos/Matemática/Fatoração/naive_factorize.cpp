vector<int> factorize(int n) {
    vector<int> factors;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n != 1) {
        factors.push_back(n);
    }
    return factors;
}

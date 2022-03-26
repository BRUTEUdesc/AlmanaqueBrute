bool is_prime(int n) {
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0) return false;
    return true;
}

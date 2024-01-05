bool is_prime(int n) {
    for (long long d = 2; d * d <= n; d++) {
<<<<<<< HEAD
        if (n % d == 0) {
            return false;
        }
=======
        if (n % d == 0) {
            return false;
        }
>>>>>>> master
    }
    return true;
}

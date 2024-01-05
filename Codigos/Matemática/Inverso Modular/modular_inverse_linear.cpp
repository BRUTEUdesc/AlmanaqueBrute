ll inv[MAX];

void compute_inv(const ll m = MOD) {
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
}

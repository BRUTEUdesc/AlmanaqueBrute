const ll INVB = (MOD + 1) / 2; // Modular inverse of the base, for 2 it is (MOD+1)/2

ll inv[MAX];

void compute_inv() {
    inv[1] = 1;
    for(int i = 2; i < MAX; ++i)
        inv[i] = inv[i-1] * INVB % MOD;
}

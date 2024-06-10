const ll INVB = (MOD + 1) / 2; // Modular inverse of the base,
                               // for 2 it is (MOD+1)/2

ll inv[MAX]; // Modular inverse of b^i

void compute_inv() {
    inv[0] = 1;
    for (int i = 1; i < MAX; i++) inv[i] = inv[i - 1] * INVB % MOD;
}

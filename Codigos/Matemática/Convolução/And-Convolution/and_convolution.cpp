template <int MOD>
vector<int> and_convolution(vector<int> A, vector<int> B) {
    int n = (int)max(A.size(), B.size());
    int N = 0, two = 1;
    while (two < n) {
        two <<= 1;
        N++;
    }
    A.resize(1 << N);
    B.resize(1 << N);
    vector<int> C(1 << N);
    for (int j = 0; j < N; j++) {
        for (int i = (1 << N) - 1; i >= 0; i--) {
            if (~i >> j & 1) {
                A[i] = (A[i] + A[i | (1 << j)]) % MOD;
                B[i] = (B[i] + B[i | (1 << j)]) % MOD;
            }
        }
    }
    for (int i = 0; i < 1 << N; i++) C[i] = 1LL * A[i] * B[i] % MOD;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < 1 << N; i++)
            if (~i >> j & 1) C[i] = (C[i] - C[i | (1 << j)] + MOD) % MOD;
    }
    return C;
}

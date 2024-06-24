template <int MOD>
vector<int> lcm_convolution(vector<int> A, vector<int> B) {
    int N = (int)max(A.size(), B.size());
    A.resize(N + 1);
    B.resize(N + 1);
    vector<int> C(N + 1), a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            a[j] = (a[j] + A[i]) % MOD;
            b[j] = (b[j] + B[i]) % MOD;
        }
        C[i] = 1LL * a[i] * b[i] % MOD;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i) C[j] = (C[j] - C[i] + MOD) % MOD;
    return C;
}

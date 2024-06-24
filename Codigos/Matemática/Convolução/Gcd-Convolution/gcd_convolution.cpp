template <int MOD>
vector<int> gcd_convolution(vector<int> A, vector<int> B) {
    int N = (int)max(A.size(), B.size());
    A.resize(N + 1);
    B.resize(N + 1);
    vector<int> C(N + 1);
    for (int i = 1; i <= N; i++) {
        int a = 0;
        int b = 0;
        for (int j = i; j <= N; j += i) {
            a = (a + A[j]) % MOD;
            b = (b + B[j]) % MOD;
        }
        C[i] = 1LL * a * b % MOD;
    }
    for (int i = N; i >= 1; i--)
        for (int j = 2 * i; j <= N; j += i) C[i] = (C[i] - C[j] + MOD) % MOD;
    return C;
}

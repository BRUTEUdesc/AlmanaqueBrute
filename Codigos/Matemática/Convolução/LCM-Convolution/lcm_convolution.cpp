vector<mint> lcm_convolution(vector<mint> A, vector<mint> B) {
    int N = (int)max(A.size(), B.size());
    A.resize(N + 1);
    B.resize(N + 1);
    vector<mint> C(N + 1), a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            a[j] += A[i];
            b[j] += B[i];
        }
        C[i] = a[i] * b[i];
    }
    for (int i = 1; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i) C[j] -= C[i];
    return C;
}

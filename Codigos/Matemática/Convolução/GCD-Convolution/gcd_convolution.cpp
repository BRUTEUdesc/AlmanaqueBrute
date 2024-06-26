vector<mint> gcd_convolution(vector<mint> A, vector<mint> B) {
    int N = (int)max(A.size(), B.size());
    A.resize(N + 1);
    B.resize(N + 1);
    vector<mint> C(N + 1);
    for (int i = 1; i <= N; i++) {
        mint a = 0;
        mint b = 0;
        for (int j = i; j <= N; j += i) {
            a += A[j];
            b += B[j];
        }
        C[i] = a * b;
    }
    for (int i = N; i >= 1; i--)
        for (int j = 2 * i; j <= N; j += i) C[i] -= C[j];
    return C;
}

vector<mint> or_convolution(vector<mint> A, vector<mint> B) {
    int n = (int)max(A.size(), B.size());
    int N = 0, two = 1;
    while (two < n) {
        two <<= 1;
        N++;
    }
    A.resize(1 << N);
    B.resize(1 << N);
    vector<mint> C(1 << N);
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < 1 << N; i++) {
            if (i >> j & 1) {
                A[i] += A[i ^ (1 << j)];
                B[i] += B[i ^ (1 << j)];
            }
        }
    }
    for (int i = 0; i < 1 << N; i++) C[i] = A[i] * B[i];
    for (int j = N - 1; j >= 0; j--) {
        for (int i = (1 << N) - 1; i >= 0; i--)
            if (i >> j & 1) C[i] -= C[i ^ (1 << j)];
    }
    return C;
}

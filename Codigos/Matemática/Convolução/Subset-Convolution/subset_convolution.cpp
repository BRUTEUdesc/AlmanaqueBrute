vector<mint> subset_convolution(vector<mint> A, vector<mint> B) {
    int n = int(max(A.size(), B.size()));
    int N = 0;
    while ((1 << N) < n) N++;
    A.resize(1 << N), B.resize(1 << N);
    vector a(1 << N, vector<mint>(N + 1)), b(1 << N, vector<mint>(N + 1));
    for (int i = 0; i < 1 << N; i++) {
        int popcnt = __builtin_popcount(i);
        a[i][popcnt] = A[i];
        b[i][popcnt] = B[i];
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < 1 << N; i++) {
            if (~i >> j & 1) continue;
            for (int popcnt = 0; popcnt <= N; popcnt++) {
                a[i][popcnt] += a[i ^ (1 << j)][popcnt];
                b[i][popcnt] += b[i ^ (1 << j)][popcnt];
            }
        }
    }
    vector c(1 << N, vector<mint>(N + 1));
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j <= N; j++)
            for (int k = 0; k + j <= N; k++) c[i][j + k] += a[i][j] * b[i][k];
    }
    for (int j = N - 1; j >= 0; j--) {
        for (int i = (1 << N) - 1; i >= 0; i--) {
            if (~i >> j & 1) continue;
            for (int popcnt = 0; popcnt <= N; popcnt++)
                c[i][popcnt] -= c[i ^ (1 << j)][popcnt];
        }
    }
    vector<mint> ans(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        int popcnt = __builtin_popcount(i);
        ans[i] = c[i][popcnt];
    }
    return ans;
}

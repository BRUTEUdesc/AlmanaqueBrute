vector<mint> xor_convolution(vector<mint> A, vector<mint> B) {
    int n = int(A.size());
    for (int rep = 0; rep < 2; rep++) {
        for (int len = n >> 1; len; len >>= 1) {
            for (int i = 0; i < n; i += len << 1) {
                for (int j = 0; j < len; j++) {
                    int id = i + j;
                    mint x = A[id];
                    mint y = A[id + len];
                    A[id] = x + y;
                    A[id + len] = x - y;
                }
            }
        }
        swap(A, B);
    }
    vector<mint> ans(n);
    for (int i = 0; i < n; i++) ans[i] = A[i] * B[i];
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                int id = i + j;
                mint x = ans[id];
                mint y = ans[id + len];
                ans[id] = x + y;
                ans[id + len] = x - y;
            }
        }
    }
    return ans;
}

vector<mint> xor_multiply(vector<mint> A, vector<mint> B) {
    int N = 1;
    while (N < int(A.size())) N <<= 1;
    A.resize(N);
    B.resize(N);
    auto ans = xor_convolution(A, B);
    for (int i = 0; i < N; i++) ans[i] /= N;
    return ans;
}

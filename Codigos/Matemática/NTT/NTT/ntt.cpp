template <int MOD, typename T = Mint<MOD>>
void ntt(vector<T> &a, bool inv = 0) {
    int n = (int)a.size();
    auto b = a;
    T g = 1;
    while ((g ^ (MOD / 2)) == 1) g += 1;
    if (inv) g = T(1) / g;
    for (int step = n / 2; step; step /= 2) {
        T w = g ^ (MOD / (n / step)), wn = 1;
        for (int i = 0; i < n / 2; i += step) {
            for (int j = 0; j < step; j++) {
                auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
                b[i + j] = u + v;
                b[i + n / 2 + j] = u - v;
            }
            wn = wn * w;
        }
        swap(a, b);
    }
    if (inv) {
        T invn = T(1) / n;
        for (int i = 0; i < n; i++) a[i] *= invn;
    }
}

template <int MOD>
vector<int> multiply(vector<int> &ta, vector<int> &tb) {
    using T = Mint<MOD>;
    int n = (int)ta.size(), m = (int)tb.size();
    int t = n + m - 1, sz = 1;
    while (sz < t) sz <<= 1;

    vector<T> a(sz), b(sz), c(sz);
    for (int i = 0; i < n; i++) a[i] = ta[i];
    for (int i = 0; i < m; i++) b[i] = tb[i];

    ntt<MOD>(a, 0), ntt<MOD>(b, 0);
    for (int i = 0; i < sz; i++) c[i] = a[i] * b[i];
    ntt<MOD>(c, 1);

    vector<int> res(sz);
    for (int i = 0; i < sz; i++) res[i] = c[i].v;
    while ((int)res.size() > t && res.back() == 0) res.pop_back();
    return res;
}
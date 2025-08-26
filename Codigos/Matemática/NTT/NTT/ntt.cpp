const int MOD = mod;
void ntt(vector<mint> &a, bool inv = 0) {
    int n = (int)a.size();
    auto b = a;
    mint g = 1;
    while ((g ^ (MOD / 2)) == 1) g += 1;
    if (inv) g = mint(1) / g;
    for (int step = n / 2; step; step /= 2) {
        mint w = g ^ (MOD / (n / step)), wn = 1;
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
        mint invn = mint(1) / n;
        for (int i = 0; i < n; i++) a[i] *= invn;
    }
}

vector<mint> multiply(vector<mint> a, vector<mint> b) {
    int n = (int)a.size(), m = (int)b.size();
    int t = n + m - 1, sz = 1;
    while (sz < t) sz <<= 1;
    a.resize(sz), b.resize(sz);
    ntt(a, 0), ntt(b, 0);
    for (int i = 0; i < sz; i++) a[i] *= b[i];
    ntt(a, 1);
    while ((int)a.size() > t) a.pop_back();
    return a;
}

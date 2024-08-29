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

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll g = extended_gcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

ll crt(array<int, 2> rem, array<int, 2> mod) {
    __int128 ans = rem[0], m = mod[0];
    for (int i = 1; i < 2; i++) {
        ll x, y;
        ll g = extended_gcd(mod[i], (ll)m, x, y);
        if ((ans - rem[i]) % g != 0) return -1;
        ans = ans + (__int128)1 * (rem[i] - ans) * (m / g) * y;
        m = (__int128)(mod[i] / g) * (m / g) * g;
        ans = (ans % m + m) % m;
    }
    return (ll)ans;
}

vector<ll> big_multiply(vector<int> &a, vector<int> &b) {
    const int MOD1 = 1004535809;
    const int MOD2 = 1092616193;
    vector<int> c1 = multiply<MOD1>(a, b);
    vector<int> c2 = multiply<MOD2>(a, b);
    vector<ll> res(c1.size());
    for (int i = 0; i < (int)res.size(); i++) res[i] = crt({c1[i], c2[i]}, {MOD1, MOD2});
    return res;
}
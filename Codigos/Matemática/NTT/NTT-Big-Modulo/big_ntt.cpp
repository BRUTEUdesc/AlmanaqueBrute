template <auto MOD, typename T = Mint<MOD>>
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

template <auto MOD, typename T = Mint<MOD>>
vector<T> multiply(vector<T> a, vector<T> b) {
    int n = (int)a.size(), m = (int)b.size();
    int t = n + m - 1, sz = 1;
    while (sz < t) sz <<= 1;
    a.resize(sz), b.resize(sz);
    ntt<MOD>(a, 0), ntt<MOD>(b, 0);
    for (int i = 0; i < sz; i++) a[i] *= b[i];
    ntt<MOD>(a, 1);
    while ((int)a.size() > t) a.pop_back();
    return a;
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
    ll x, y;
    ll g = extended_gcd(mod[1], (ll)m, x, y);
    if ((ans - rem[1]) % g != 0) return -1;
    ans = ans + (__int128)1 * (rem[1] - ans) * (m / g) * y;
    m = (__int128)(mod[1] / g) * (m / g) * g;
    ans = (ans % m + m) % m;
    return (ll)ans;
}

template <auto MOD1, auto MOD2, typename T = Mint<MOD1>, typename U = Mint<MOD2>>
vector<ll> big_multiply(vector<ll> ta, vector<ll> tb) {
    vector<T> a1(ta.size()), b1(tb.size());
    vector<U> a2(ta.size()), b2(tb.size());
    for (int i = 0; i < (int)ta.size(); i++) a1[i] = ta[i];
    for (int i = 0; i < (int)tb.size(); i++) b1[i] = tb[i];
    for (int i = 0; i < (int)ta.size(); i++) a2[i] = ta[i];
    for (int i = 0; i < (int)tb.size(); i++) b2[i] = tb[i];
    auto c1 = multiply<MOD1>(a1, b1);
    vector<ll> res(c1.size());
    for (int i = 0; i < (int)res.size(); i++)
        res[i] = crt({c1[i].v, c2[i].v}, {MOD1, MOD2});
    return res;
}

const int MOD1 = 1004535809;
const int MOD2 = 1092616193;
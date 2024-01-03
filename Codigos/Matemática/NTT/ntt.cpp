typedef long long ll;
typedef vector<ll> poly;

ll mod[3] = {998244353LL, 1004535809LL, 1092616193LL};
ll root[3] = {102292LL, 12289LL, 23747LL};
ll root_1[3] = {116744195LL, 313564925LL, 642907570LL};
ll root_pw[3] = {1LL << 23, 1LL << 21, 1LL << 21};

ll modInv(ll b, ll m) {
    ll e = m - 2;
    ll res = 1;
    while (e) {
        if (e & 1) { res = (res * b) % m; }
        e /= 2;
        b = (b * b) % m;
    }
    return res;
}

void ntt(poly &a, bool invert, int id) {
    ll n = (ll)a.size(), m = mod[id];
    for (ll i = 1, j = 0; i < n; ++i) {
        ll bit = n >> 1;
        for (; j >= bit; bit >>= 1) { j -= bit; }
        j += bit;
        if (i < j) { swap(a[i], a[j]); }
    }
    for (ll len = 2, wlen; len <= n; len <<= 1) {
        wlen = invert ? root_1[id] : root[id];
        for (ll i = len; i < root_pw[id]; i <<= 1) { wlen = (wlen * wlen) % m; }
        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i + j], v = (a[i + j + len / 2] * w) % m;
                a[i + j] = (u + v) % m;
                a[i + j + len / 2] = (u - v + m) % m;
                w = (w * wlen) % m;
            }
        }
    }
    if (invert) {
        ll inv = modInv(n, m);
        for (ll i = 0; i < n; i++) { a[i] = (a[i] * inv) % m; }
    }
}

poly convolution(poly a, poly b, int id = 0) {
    ll n = 1LL, len = (1LL + a.size() + b.size());
    while (n < len) { n *= 2; }
    a.resize(n);
    b.resize(n);
    ntt(a, 0, id);
    ntt(b, 0, id);
    poly answer(n);
    for (ll i = 0; i < n; i++) { answer[i] = (a[i] * b[i]); }
    ntt(answer, 1, id);
    return answer;
}

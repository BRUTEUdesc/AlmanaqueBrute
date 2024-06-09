const int MOD = 998244353;
const int root_ntt = 102292;
const int len_ntt = 1 << 23;

using mint = Mint<MOD>;
using poly = vector<mint>;

void ntt(poly &a, bool inv = 0) {
    int n = (int)a.size();

    for (int i = 0; i < n; i++) {
        int bit = n >> 1;
        int j = 0, k = i;
        while (bit > 0) {
            if (k & 1)
                j += bit;
            k >>= 1;
            bit >>= 1;
        }
        if (i < j)
            swap(a[i], a[j]);
    }

    poly wn(n / 2);
    mint root = root_ntt;   // change according to MOD
    int root_len = len_ntt; // change according to MOD

    while (root_len > n) {
        root = root * root;
        root_len >>= 1;
    }

    if (inv)
        root = mint(1) / root;

    for (int i = 0; i < n / 2; i++)
        wn[i] = (i == 0) ? 1 : wn[i - 1] * root;

    for (int len = 2; len <= n; len <<= 1) {
        int aux = len / 2;
        int step = n / len;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < aux; j++) {
                mint v = a[i + j + aux] * wn[step * j];
                a[i + j + aux] = a[i + j] - v;
                a[i + j] = a[i + j] + v;
            }
        }
    }
    if (inv) {
        mint invn = mint(1) / n;
        for (int i = 0; i < n; i++)
            a[i] = a[i] * invn;
    }
}

vector<int> multiply(vector<int> &ta, vector<int> &tb) {
    int n = int(ta.size()), m = int(tb.size());
    int t = n + m - 1, sz = 1;
    while (sz < t)
        sz <<= 1;

    poly a(sz), b(sz), c(sz);

    for (int i = 0; i < sz; i++) {
        a[i].v = i < n ? ta[i] : 0;
        b[i].v = i < m ? tb[i] : 0;
    }

    ntt(a, 0), ntt(b, 0);
    for (int i = 0; i < sz; i++)
        c[i] = a[i] * b[i];
    ntt(c, 1);

    vector<int> res(sz);
    for (int i = 0; i < sz; i++)
        res[i] = c[i].v;

    while ((int)res.size() > t && res.back() == 0)
        res.pop_back();

    return res;
}
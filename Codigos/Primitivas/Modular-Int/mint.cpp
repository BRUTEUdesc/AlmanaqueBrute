template <int MOD> struct Mint {
    using m = Mint<MOD>;
    int v;
    Mint() : v(0) { }
    Mint(ll val) {
        v = (-MOD <= val && val < MOD) ? (int)val : (int)(val % MOD);
        v += (v < 0) * MOD;
    }
    bool operator==(m o) const { return v == o.v; }
    bool operator!=(m o) const { return v != o.v; }
    bool operator<(m o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res = 1;
        while (e > 0) {
            if (e & 1)
                res = res * b;
            b = b * b, e >>= 1;
        }
        return res;
    }
    friend m operator-(m a, m b) { return (a.v -= b.v) < 0 ? a.v + MOD : a.v; }
    friend m operator+(m a, m b) { return a - (MOD - b.v); }
    friend m operator*(m a, m b) { return (ll)a.v * b.v; }
    friend m operator/(m a, m b) { return a * b.pwr(b, MOD - 2); }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD = 998244353;
using mint = Mint<MOD>;
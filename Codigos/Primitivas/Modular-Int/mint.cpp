template <int MOD> struct Mint {
    using m = Mint;
    int v;
    Mint() : v(0) { }
    Mint(ll val) {
        v = (-MOD <= val && val < MOD) ? (int)val : (int)(val % MOD);
        if (v < 0) {
            v += MOD;
        }
    }
    bool operator==(const m &o) const { return v == o.v; }
    bool operator!=(const m &o) const { return v != o.v; }
    bool operator<(const m &o) const { return v < o.v; }
    m pwr(m b, ll e) const {
        m res = 1;
        while (e > 0) {
            if (e & 1) {
                res = res * b;
            }
            b = b * b;
            e >>= 1;
        }
        return res;
    }
    friend m operator+(m a, const m &b) {
        a.v += b.v;
        return a.v >= MOD ? a.v - MOD : a.v;
    }
    friend m operator-(m a, const m &b) {
        a.v -= b.v;
        return a.v < 0 ? a.v + MOD : a.v;
    }
    friend m operator*(m a, const m &b) { return (ll)a.v * b.v % MOD; }
    friend m operator/(m a, const m &b) { return a * b.pwr(b, MOD - 2); }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD = 998244353; // o MOD tem que ser primo
using mint = Mint<MOD>;

template <int MOD> struct Mint {
    using m = Mint;
    int v;
    Mint() : v(0) { }
    Mint(ll val) {
        if (val < -MOD or val >= 2 * MOD) {
            val %= MOD;
        }
        if (val >= MOD) {
            val -= MOD;
        }
        if (val < 0) {
            val += MOD;
        }
        v = int(val);
    }
    bool operator==(const m &o) const { return v == o.v; }
    bool operator!=(const m &o) const { return v != o.v; }
    bool operator<(const m &o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res = 1;
        while (e > 0) {
            if (e & 1) {
                res *= b;
            }
            b *= b, e >>= 1;
        }
        return res;
    }
    m &operator+=(const m &o) {
        v += o.v;
        if (v >= MOD) {
            v -= MOD;
        }
        return *this;
    }
    m &operator-=(const m &o) {
        v -= o.v;
        if (v < 0) {
            v += MOD;
        }
        return *this;
    }
    m &operator*=(const m &o) {
        v = int(ll(v) * o.v % MOD);
        return *this;
    }
    m &operator/=(const m &o) { return *this *= pwr(o, MOD - 2); }
    m &operator^=(ll e) {
        assert(e >= 0);
        return *this = pwr(*this, e);
    }
    friend m operator+(m a, const m &b) { return a += b; }
    friend m operator-(m a, const m &b) { return a -= b; }
    friend m operator*(m a, const m &b) { return a *= b; }
    friend m operator/(m a, const m &b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
    friend ostream &operator<<(ostream &os, const m &a) { return os << a.v; }
    friend istream &operator>>(istream &is, m &a) {
        ll x;
        is >> x, a = m(x);
        return is;
    }
};

const int MOD = 998244353; // o MOD tem que ser primo
using mint = Mint<MOD>;

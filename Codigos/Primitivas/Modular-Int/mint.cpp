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
        v = (int)val;
    }
    bool operator==(const m &o) const { return v == o.v; }
    bool operator!=(const m &o) const { return v != o.v; }
    bool operator<(const m &o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res;
        for (res = 1; e > 0; e >>= 1, b *= b) {
            if (e & 1) {
                res *= b;
            }
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
    m &operator*=(const m &o) { return *this = m((ll)v * o.v % MOD); }
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

template <int mod> struct Mint {
    using m = Mint;
    int v;
    Mint() : v(0) { }
    Mint(ll v) {
        if (v < -mod or v >= 2 * mod) {
            v %= mod;
        }
        if (v >= mod) {
            v -= mod;
        }
        if (v < 0) {
            v += mod;
        }
        v = int(v);
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
        if ((v += o.v) >= mod) {
            v -= mod;
        }
        return *this;
    }
    m &operator-=(const m &o) {
        if ((v -= o.v) < 0) {
            v += mod;
        }
        return *this;
    }
    m &operator*=(const m &o) {
        v = int(ll(v) * o.v % mod);
        return *this;
    }
    m &operator/=(const m &o) { return *this *= pwr(o, mod - 2); }
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

const int mod = 998244353;
using mint = Mint<mod>;
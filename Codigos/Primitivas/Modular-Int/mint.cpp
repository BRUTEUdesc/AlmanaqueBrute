template <int mod> struct Mint {
    using m = Mint;
    int val;
    Mint() : val(0) { }
    Mint(ll v) {
        if (v < -mod || v >= 2 * mod) {
            v %= mod;
        }
        if (v >= mod) {
            v -= mod;
        }
        if (v < 0) {
            v += mod;
        }
        val = int(v);
    }
    m pwr(m b, ll e) {
        m res = 1;
        while (e) {
            if (e & 1)
                res *= b;
            b *= b, e >>= 1;
        }
        return res;
    }
    m &operator+=(const m &o) {
        val += o.val;
        if (val >= mod) {
            val -= mod;
        }
        return *this;
    }
    m &operator-=(const m &o) {
        val -= o.val;
        if (val < 0) {
            val += mod;
        }
        return *this;
    }
    m &operator*=(const m &o) {
        val = int((ll)val * o.val % mod);
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
    friend ostream &operator<<(ostream &os, const m &a) { return os << a.val; }
    friend istream &operator>>(istream &is, m &a) {
        ll x;
        is >> x, a = m(x);
        return is;
    }
};

const int mod = 998244353;
using mint = Mint<mod>;

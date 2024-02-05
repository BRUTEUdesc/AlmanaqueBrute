template <int mod> struct Mint {
    using m = Mint;
    int val;
    Mint() : val(0) { }
    Mint(ll v) {
        if (v < -mod || v >= 2 * mod)
            v %= mod;
        if (v >= mod)
            v -= mod;
        if (v < 0)
            v += mod;
        val = v;
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
        if ((val += o.val) >= mod)
            val -= mod;
        return *this;
    }
    m &operator-=(const m &o) {
        if ((val -= o.val) < 0)
            val += mod;
        return *this;
    }
    m &operator*=(const m &o) {
        val = (ll)val * o.val % mod;
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
};

const int mod = 998244353;
using mint = Mint<mod>;

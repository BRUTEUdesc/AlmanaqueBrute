template <auto MOD, typename T = decltype(MOD)>
struct Mint {
    using m = Mint<MOD, T>;
    T v;
    Mint(T val = 0) : v(val) {
        if (v < 0) v += MOD;
    }
    bool operator==(m o) const { return v == o.v; }
    bool operator!=(m o) const { return v != o.v; }
    bool operator<(m o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res = 1;
        while (e > 0) {
            if (e & 1) res *= b;
            b *= b, e >>= 1;
        }
        return res;
    }
    m& operator+=(m o) { v -= MOD - o.v; if (v < 0) v += MOD; return *this; }
    m& operator-=(m o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    m& operator*=(m o) { v = (T)((__int128)v * o.v % MOD); return *this; }
    // se quiser otimizar constante, ao inves de (__int128) use (ll) se o T for `int`
    m& operator/=(m o) { return *this *= o.pwr(o, MOD - 2); }
    m& operator^=(ll e) { return *this = pwr(*this, e); }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD = 998244353;
using mint = Mint<MOD>;

const ll BIG_MOD = 9223372036737335297LL; // 549755813881 * 2^24 + 1
ll root_ntt = 2419180138865645092LL;      // essa constante pode ser calculada
                                          // fazendo 3 ^ ((MOD - 1) / (1 << 24))
int len_ntt = 1 << 24;

using mint = Mint<BIG_MOD>;

using poly = vector<mint>;

void big_ntt(poly &a, bool inv = 0) {
    // exatamente o mesmo código da ntt
}

vector<ll> big_multiply(vector<ll> &ta, vector<ll> &tb) {
    // exatamente o mesmo código da multiply, porem usando vector<ll> ao inves de
    // vector<int> e chamando big_ntt ao inves de ntt
    // ...
    vector<ll> res(sz); // lembrando, usar vector<ll> ao inves de vector<int>
    // ...
    return res;
}
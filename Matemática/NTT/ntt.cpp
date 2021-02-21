typedef long long ll;
typedef vector<ll> poly;

ll mod = 998244353LL;
ll root = 15311432LL;
ll root_1 = 469870224LL;
ll root_pw = 1 << 23;

ll modInv(ll b){
    ll e = mod - 2;
    ll res = 1;
    while(e){
        if(e & 1) res = (res * b) % mod;
        e /= 2;
        b = (b * b) % mod;
    }
    return res;
}

void ntt(poly &a, bool invert = 0){
    ll n = (ll)a.size();
    for(ll i = 1, j = 0; i<n; ++i){
        ll bit = n >> 1;
        for( ; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap (a[i], a[j]);
    }
    for(ll len = 2, wlen; len <= n; len <<= 1){
        wlen = invert? root_1 : root;
        for(ll i = len; i < root_pw; i<<=1)
            wlen = (wlen * wlen) % mod;
        for(ll i = 0; i < n; i+=len){
            ll w = 1;
            for(ll j = 0; j < len/2; j++){
                ll u = a[i+j], v = (a[i+j+len/2] * w) % mod;
                a[i+j] = (u+v) % mod;
                a[i+j+len/2] = (u-v+mod) % mod;
                w = (w * wlen) % mod;
             }
        }
    }
    if(invert){
        ll inv = modInv(n);
        for(ll i = 0; i < n; i++)
            a[i] = (a[i] * inv) % mod;
    }
}

poly convolution(poly &a, poly &b){
    ll n = 1LL, len = (1LL + a.size() + b.size());
    while(n < len) n *= 2;
    a.resize(n); b.resize(n);
    ntt(a); ntt(b);
    poly answer(n);
    for(ll i = 0; i < n; i++) answer[i] = (a[i] * b[i]);
    ntt(answer, 1);
    return answer;
}

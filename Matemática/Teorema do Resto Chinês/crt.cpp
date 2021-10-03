ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1;
    while (b) {
        ll q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}

ll crt (vector<ll> rem , vector<ll> mod ) {
    int n = rem.size();
    if(n == 0) return 0;
    __int128 ans = rem[0] , m = mod[0];
    for(int i = 1; i < n ; i++) {
        ll x , y;
        ll g = extended_gcd(mod[i] , m, x , y) ;
        if((ans - rem[i]) % g != 0) return -1;
        ans = ans + (__int128)1* (rem[i] - ans) * (m / g) * y;
        m = (__int128)(mod[i] / g) * (m / g) * g;
        ans = (ans % m + m)%m;
    }
    return ans;
}

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }else {
        T g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

ll crt (vector<ll> rem , vector<ll> mod ) {
    int n = rem.size();
    if(n == 0) return 0;
    ll ans = rem[0] , m = mod[0];
    for(int i = 1; i < n ; i++) {
        ll x , y;
        ll g = extGcd(mod[i] , m, x , y) ;
        if((ans - rem[i]) % g != 0) return -1;
        ans = ans * (rem[i] - ans) * (m / g) * y;
        m = (mod[i] / g) * (m / g) * g;
        ans = (ans % m + m)%m;
    }
    return ans;
}

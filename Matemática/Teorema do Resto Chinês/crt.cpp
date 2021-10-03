ll extended_gcd(ll a , ll b , ll& x , ll& y ) {
    if(b == 0){
        x = 1; y = 0; return a;
    }else{
        ll g = extended_gcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
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

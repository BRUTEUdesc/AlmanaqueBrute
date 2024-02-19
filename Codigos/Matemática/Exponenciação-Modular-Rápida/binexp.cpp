ll binexp(ll n, ll e) {
    ll ret = 1; 
    while (e) {
        if (e&1) ret = ret * n % mod; 
        n = n * n % mod; 
        e >>= 1; 
    } 
    return ret; 
} 

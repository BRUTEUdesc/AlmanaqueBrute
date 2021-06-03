long long exp_mod(long long base, long long exp, long long mod){
    long long b = base, res = 1;
    while(exp){
        if(exp & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return res;
}

const int lim = 17 ; // setar para o maximo de itens
long double dist[lim][lim]; // é preciso dar as distâncias de n para n
long double dp[lim][1<<lim];

int limMask = (1<<lim) - 1; // 2**(maximo de itens) - 1
long double solve(int atual, int mask, int n){
    if(dp[atual][mask] != 0) return dp[atual][mask];
    
    if(mask == (1<<n) -1){
        return dp[atual][mask] = 0; // o que fazer quando chega no final 
    }
    long double res = 10000000000000.0;// pode ser maior se precisar
    if(mask == 0){
        for(int i = 0; i < n; i ++){
            if(!(mask & (1<<i))) {
                long double aux =  solve(i, mask|(1<<i) , n);
                res = min(res, aux);
            }
        }
    }else{
        for(int i = 0; i < n; i ++){
            if(!(mask & (1<<i))) {
                long double aux = dist[atual][i] + solve(i, mask|(1<<i) , n);
                res = min(res, aux);
            }
        }
    }
    
    return dp[atual][mask] = res;
}

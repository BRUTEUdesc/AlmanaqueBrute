typedef vector<vi> mat;
 
mat T;
 
mat mult(mat a, mat b) {
    mat res(a.size(), vi(b.size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            for (int k = 0; k < b[0].size(); k++) {
                res[i][j] += a[i][k] * b[k][j] % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}
 
mat exp_mod(mat b, ll exp){
    mat res(2, vi(2));
    res[0][0] = res[1][1] = 1;
    while(exp){
        if(exp & 1) res = mult(res, b);
        b = mult(b, b);
        exp /= 2;
    }
    return res;
}
 
// MUDA MUITO DE ACORDO COM O PROBLEMA
// LEIA COMO FAZER O MAPEAMENTO NO README
ll solve(int n, int k){
    T.assign(k, vi(k));

    // Preenchendo a Matriz que vai ser exponenciada
    // Exemplo de Fibonacci
    // T[0][0] = 0;
    // T[0][1] = 1;
    // T[1][0] = 1;
    // T[1][1] = 1;

    mat prod = exp_mod(T, n);

    mat vec; vec.assign(k, vi(1));
    for(int i = 0; i < k; i++) vec[i][0] = dp[i];
    
    mat ans = mult(prod, vec);
    return ans[1][1];
}
ll dp[100];
mat T;

#define MOD 1000000007

mat mult(mat a, mat b) {
    mat res(a.size(), vi(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] += a[i][k] * b[k][j] % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

mat exp_mod(mat b, ll exp) {
    mat res(b.size(), vi(b.size()));
    for (int i = 0; i < b.size(); i++) {
        res[i][i] = 1;
    }

    while (exp) {
        if (exp & 1) {
            res = mult(res, b);
        }
        b = mult(b, b);
        exp /= 2;
    }
    return res;
}

// MUDA MUITO DE ACORDO COM O PROBLEMA
// LEIA COMO FAZER O MAPEAMENTO NO README
ll solve(ll exp, ll dim) {
    if (exp < dim) {
        return dp[exp];
    }

    T.assign(dim, vi(dim));
    // TO DO: Preencher a Matriz que vai ser exponenciada
    // T[0][1] = 1;
    // T[1][0] = 1;
    // T[1][1] = 1;

    mat prod = exp_mod(T, exp);

    mat vec;
    vec.assign(dim, vi(1));
    for (int i = 0; i < dim; i++) {
        vec[i][0] = dp[i]; // Valores iniciais
    }

    mat ans = mult(prod, vec);
    return ans[0][0];
}
ll dp[100];
mat T; // mat é tipo vector<vector<ll>>

#define MOD 1000000007

mat *operator(mat a, mat b) {
    mat resp(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                resp[i][j] += a[i][k] * b[k][j] % mod;
                resp[i][j] %= mod;
            }
        }
    }
    return resp;
}

mat operator^(mat a, ll k) {
    mat resp(a.size(), vector<ll>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        resp[i][i] = 1;
    }

    while (k) {
        if (k & 1) {
            resp = resp * a;
        }

        a = a * a;
        k >>= 1;
    }

    return resp;
}

// MUDA MUITO DE ACORDO COM O PROBLEMA
// LEIA COMO FAZER O MAPEAMENTO NO README
ll solve(ll exp, ll dim) {
    if (exp < dim) {
        return dp[exp];
    }

    T.assign(dim, vi(dim));
    // TO DO: Preencher a Matriz que vai ser
    // exponenciada T[0][1] = 1; T[1][0] = 1;
    // T[1][1] = 1;

    mat prod = T ^ exp;

    mat vec;
    vec.assign(dim, vi(1));
    for (int i = 0; i < dim; i++) {
        vec[i][0] = dp[i]; // Valores iniciais
    }

    mat ans = prod * vec;
    return ans[0][0];
}

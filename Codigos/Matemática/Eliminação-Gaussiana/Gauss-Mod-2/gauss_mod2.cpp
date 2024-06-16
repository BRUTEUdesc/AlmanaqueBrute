const int M = 105;
const int INF = 2; // nao tem que ser infinito ou um numero grande
                   // so serve para indicar que tem infinitas solucoes

int gauss(vector<bitset<M>> a, int n, int m, bitset<M> &ans) {
    vector<int> where(m, -1);

    for (int col = 0, row = 0; col < m && row < n; col++) {
        for (int i = row; i < n; i++) {
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        }
        if (!a[row][col]) continue;
        where[col] = row;

        for (int i = 0; i < n; i++)
            if (i != row && a[i][col]) a[i] ^= a[row];
        row++;
    }

    ans.reset();
    for (int i = 0; i < m; i++)
        if (where[i] != -1) ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > 0) return 0; // Sem solucao
    }

    for (int i = 0; i < m; i++)
        if (where[i] == -1) return INF; // Infinitas solucoes
    // Unica solucao (retornada no bitset ans)
    return 1;
}

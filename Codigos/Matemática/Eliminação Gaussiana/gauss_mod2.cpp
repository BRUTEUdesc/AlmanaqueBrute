const int N = 105;
const int INF = 2; // tanto faz

// n -> numero de equacoes, m -> numero de variaveis
// a[i][j] para j em [0, m - 1] -> coeficiente da variavel j na iesima equacao
// a[i][j] para j == m -> resultado da equacao da iesima linha
// ans -> bitset vazio, que retornara a solucao do sistema (caso exista)
int gauss(vector<bitset<N>> a, int n, int m, bitset<N> &ans) {
    vector<int> where(m, -1);

    for (int col = 0, row = 0; col < m && row < n; col++) {
        for (int i = row; i < n; i++) {
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        }
        if (!a[row][col]) {
            continue;
        }
        where[col] = row;

        for (int i = 0; i < n; i++) {
            if (i != row && a[i][col]) {
                a[i] ^= a[row];
            }
        }
        row++;
    }

    for (int i = 0; i < m; i++) {
        if (where[i] != -1) {
            ans[i] = a[where[i]][m] / a[where[i]][i];
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += ans[j] * a[i][j];
        }
        if (abs(sum - a[i][m]) > 0) {
            return 0; // Sem solucao
        }
    }

    for (int i = 0; i < m; i++) {
        if (where[i] == -1) {
            return INF; // Infinitas solucoes
        }
    }
    return 1; // Unica solucao (retornada no bitset ans)
}

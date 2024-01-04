const int MAX = 10;
ll tree[MAX][MAX][MAX][MAX][MAX][MAX][MAX][MAX]; // insira a quantidade
                                                 // necessaria de dimensoes

int lsONE(int x) {
    return x & (-x);
}

ll query(vector<int> s, int pos) {
    ll sum = 0;
    while (s[pos] > 0) {
        if (pos < s.size() - 1) {
            sum += query(s, pos + 1);
        } else {
            sum += tree[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]];
        }
        s[pos] -= lsONE(s[pos]);
    }
    return sum;
}

void update(vector<int> s, int pos, int v) {
    while (s[pos] < MAX + 1) {
        if (pos < s.size() - 1) {
            update(s, pos + 1, v);
        } else {
            tree[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]] += v;
        }

        s[pos] += lsONE(s[pos]);
    }
}
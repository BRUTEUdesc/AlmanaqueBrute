struct XorTrie {
    const int bits = 30;
    vector<vector<int>> go;
    int root = 0, cnt = 1;
    XorTrie() { }
    XorTrie(int n) { go.assign((n + 1) * bits, vector<int>(2, -1)); }
    void insert(int x) {
        int v = root;
        for (int i = bits - 1; i >= 0; i--) {
            int b = x >> i & 1;
            if (go[v][b] == -1) go[v][b] = cnt++;
            v = go[v][b];
        }
    }
    int max_xor(int x) {
        int v = root;
        int ans = 0;
        if (cnt <= 1) return -1;
        for (int i = bits - 1; i >= 0; i--) {
            int b = x >> i & 1;
            int good = go[v][!b];
            int bad = go[v][b];
            if (good != -1) {
                v = good;
                ans |= 1 << i;
            } else if (bad != -1) {
                v = bad;
            }
        }
        return ans;
    }
    int min_xor(int x) {
        int flipped = x ^ ((1 << bits) - 1);
        int query = max_xor(flipped);
        if (query == -1) return -1;
        return x ^ flipped ^ query;
    }
};

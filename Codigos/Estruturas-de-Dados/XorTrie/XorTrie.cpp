struct XorTrie {
    const int bits = 30;
    vector<vector<int>> go;
    int root, cnt;
    int new_node() {
        go[cnt][0] = go[cnt][1] = -1;
        return cnt++;
    }
    void insert(int x) {
        int v = root;
        for (int i = bits - 1; i >= 0; i--) {
            int now = x >> i & 1;
            if (go[v][now] == -1) {
                go[v][now] = new_node();
            }
            v = go[v][now];
        }
    }
#warning se a trie estiver vazia, a query retornara -1
    int max_xor(int x) {
        int v = root;
        int ans = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int now = x >> i & 1;
            int good = go[v][!now];
            int bad = go[v][now];
            if (good != -1) {
                v = good;
                ans |= 1 << i;
            } else if (bad != -1) {
                v = bad;
            } else
                return -1;
        }
        return ans;
    }
    int min_xor(int x) {
        int flipped = x ^ ((1 << bits) - 1);
        int query = max_xor(flipped);
        if (query == -1)
            return -1;
        return x ^ flipped ^ query;
    }
    XorTrie(int n) {
        go.assign((n + 1) * bits, vector<int>(2));
        cnt = 0;
        root = new_node();
    }
};

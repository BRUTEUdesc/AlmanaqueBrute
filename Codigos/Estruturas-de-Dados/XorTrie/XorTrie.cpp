template <int bits = 30> struct XorTrie {
    vector<vector<int>> go;
    int root, cnt;
    int new_node() {
        go[cnt][0] = go[cnt][1] = -1;
        return cnt++;
    }
    void insert(int x) {
        int v = root;
        for (int i = bits - 1; i >= 0; i--) {
            if (go[v][x >> i & 1] == -1) {
                go[v][x >> i & 1] = new_node();
            }
            v = go[v][x >> i & 1];
        }
    }
#warning se a trie estiver vazia, a query retornara -1
    int max_xor(int x) {
        int v = root;
        int ans = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int good = go[v][~x >> i & 1];
            int bad = go[v][x >> i & 1];
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
        int v = root;
        int ans = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int good = go[v][x >> i & 1];
            int bad = go[v][~x >> i & 1];
            if (good != -1) {
                v = good;
            } else if (bad != -1) {
                v = bad;
                ans |= 1 << i;
            } else
                return -1;
        }
        return ans;
    }
    XorTrie(int n) {
        go.assign(n * (bits + 1), vector<int>(2));
        cnt = 0;
        root = new_node();
    }
};

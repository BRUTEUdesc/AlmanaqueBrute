template <int bits = 30> struct XorTrie {
    vector<vector<int>> go;
    int root, cnt;

    int new_node() {
        go[0][cnt] = -1;
        go[1][cnt] = -1;
        return cnt++;
    }

    void insert(int x) {
        int v = root;
        for (int i = bits - 1; i >= 0; i--) {
            if (go[x >> i & 1][v] == -1) {
                go[x >> i & 1][v] = new_node();
            }
            v = go[x >> i & 1][v];
        }
    }

#warning se a trie estiver vazia, a query retornara -1
    int max_xor(int x) {
        int v = root;
        int ans = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int good = go[~x >> i & 1][v];
            int bad = go[x >> i & 1][v];
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
            int good = go[x >> i & 1][v];
            int bad = go[~x >> i & 1][v];
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
        go.resize(2);
        go[0].resize(n * (bits + 1));
        go[1].resize(n * (bits + 1));
        cnt = 0;
        root = new_node();
    }
};

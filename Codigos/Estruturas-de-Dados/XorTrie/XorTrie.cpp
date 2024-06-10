template <int bits = 30> struct XorTrie {
    vector<int> o, z;
    int root, cnt;

    int new_node() {
        o[cnt] = -1;
        z[cnt] = -1;
        return cnt++;
    }

    void insert(int x) {
        int v = root;
        for (int i = bits; i >= 0; i--) {
            if (x >> i & 1) {
                if (o[v] == -1) {
                    o[v] = new_node();
                }
                v = o[v];
            } else {
                if (z[v] == -1) {
                    z[v] = new_node();
                }
                v = z[v];
            }
        }
    }

    ll max_xor(ll x) {
        int v = root;
        ll ans = 0;
        for (int i = bits; i >= 0; i--) {
            if (x >> i & 1) {
                if (z[v] != -1) {
                    v = z[v];
                } else if (o[v] != -1) {
                    v = o[v];
                    ans |= 1LL << i;
                } else {
                    return ans;
                }
            } else {
                if (o[v] != -1) {
                    v = o[v];
                    ans |= 1LL << i;
                } else if (z[v] != -1) {
                    v = z[v];
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }

    ll min_xor(ll x) {
        int v = root;
        ll ans = 0;
        for (int i = bits; i >= 0; i--) {
            if (x >> i & 1) {
                if (o[v] != -1) {
                    v = o[v];
                    ans |= 1LL << i;
                } else if (z[v] != -1) {
                    v = z[v];
                } else {
                    return ans;
                }
            } else {
                if (z[v] != -1) {
                    v = z[v];
                } else if (o[v] != -1) {
                    v = o[v];
                    ans |= 1LL << i;
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
    XorTrie(int n) {
        o.resize(n * (bits + 1));
        z.resize(n * (bits + 1));
        cnt = 0;
        root = new_node();
    }
};

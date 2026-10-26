struct trie {
    map<char, int> trie[100005];
    vector<int> value = vector<int>(100005, -1); // -1 = palavra nao inserida
    int n_nodes = 0;
    void insert(string &s, int v) {
        int id = 0;
        for (char c : s) {
            if (!trie[id].count(c)) trie[id][c] = ++n_nodes;
            id = trie[id][c];
        }
        value[id] = v;
    }
    int get_value(string &s) {
        int id = 0;
        for (char c : s) {
            if (!trie[id].count(c)) return -1;
            id = trie[id][c];
        }
        return value[id];
    }
};

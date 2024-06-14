const int N = 3e5 + 5;
#warning nao esqueca de copiar o codigo de LCA
vector<int> vir_tree[N];
vector<int> vir_nodes;

void build_virtual_tree(vector<int> S) {
    int n = (int)S.size();
    sort(S.begin(), S.end(), [&](int i, int j) { return bl::tin[i] < bl::tin[j]; });
    for (int i = 1; i < n; i++) S.emplace_back(bl::lca(S[i - 1], S[i]));
    sort(S.begin(), S.end(), [&](int i, int j) { return bl::tin[i] < bl::tin[j]; });
    S.erase(unique(S.begin(), S.end()), S.end());
    vir_nodes = S;
    n = (int)S.size();
    for (auto u : S) vir_tree[u].clear();
    vector<int> stk = {S[0]};
    for (int i = 1; i < n; i++) {
        int u = S[i];
        while (!bl::ancestor(stk.back(), u)) {
            int v = stk.back();
            stk.pop_back();
            int pai = stk.back();
            vir_tree[pai].emplace_back(v);
        }
        stk.emplace_back(u);
    }
    while (int(stk.size()) >= 2) {
        int u = stk.back();
        stk.pop_back();
        int pai = stk.back();
        vir_tree[pai].emplace_back(u);
    }
}

const int N = 3e5 + 5;
#warning nao esquece de copiar o codigo de LCA
vector<int> vir_tree[N];
vector<int> vir_nodes;

void build_virtual_tree(vector<int> S) {
    sort(S.begin(), S.end(), [&](int i, int j) { return bl::tin[i] < bl::tin[j]; });
    for (int i = 1; i < (int)S.size(); i++) S.emplace_back(bl::lca(S[i - 1], S[i]));
    sort(S.begin(), S.end(), [&](int i, int j) { return bl::tin[i] < bl::tin[j]; });
    S.erase(unique(S.begin(), S.end()), S.end());
    vir_nodes = S;
    for (auto u : S) vir_tree[u].clear();
    vector<int> stk;
    for (auto u : S) {
        while (stk.size() && !bl::ancestor(stk.back(), u)) stk.pop_back();
        if (stk.size()) vir_tree[stk.back()].emplace_back(u);
        stk.emplace_back(u);
    }
}

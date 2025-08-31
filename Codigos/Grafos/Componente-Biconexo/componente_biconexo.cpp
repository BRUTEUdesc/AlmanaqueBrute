const int N = 2e5 + 5;
int low[N], tin[N], who[N], T = 1;
vector<int> adj[N], stk;
vector<vector<int>> comp;

void dfs(int v, int p) {
    low[v] = tin[v] = T++;
    stk.emplace_back(v);
    for (auto u : adj[v]) {
        if (tin[u] == 0) {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        } else if (u != p && tin[u] < tin[v]) {
            low[v] = min(low[v], tin[u]);
        }
    }

    if (low[v] == tin[v]) {
        comp.emplace_back();
        int now;
        do {
            now = stk.back();
            who[now] = int(comp.size() - 1);
            stk.pop_back();
            comp.back().emplace_back(now);
        } while (now != v);
    }
}

const int MAXN = 1e6 + 6;

vector<int> adj[MAXN];

struct CycleFinder {
    const ll INF = 1e18;
    int n;
    vector<int> visto, pai;
    int start = -1, end = -1;
    void build(int _n) { n = _n; }
    bool dfs(int u) {
        visto[u] = 1;
        for (int v : adj[u]) {
            if (visto[v] == 0) {
                pai[v] = u;
                if (dfs(v)) return true;
            } else if (visto[v] == 1) {
                end = u;
                start = v;
                return true;
            }
        }
        visto[u] = 2;
        return false;
    }
    vector<int> get_cycle() {
        visto.assign(n, 0);
        pai.assign(n, -1);
        for (int v = 0; v < n; v++)
            if (visto[v] == 0 && dfs(v)) break;
        vector<int> cycle;
        if (start != -1) {
            cycle.emplace_back(start);
            for (int v = end; v != start; v = pai[v]) cycle.emplace_back(v);
            cycle.emplace_back(start);
            reverse(cycle.begin(), cycle.end());
        }
        return cycle;
    }
} finder;

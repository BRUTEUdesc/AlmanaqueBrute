const int MAXN = 1e6 + 6;

vector<int> adj[MAXN];

struct CycleFinder {
    int n;
    bool trivial;
    vector<int> vis, par;
    int start = -1, end = -1;
    void build(int _n, bool _trivial = 1) { 
        n = _n;
        trivial = _trivial;
        // trivial eh um flag que indica se o algoritmo deve aceitar ou nao
        // ciclos triviais, um ciclo trivial eh um ciclo de tamanho 1 ou 2
    }
    bool dfs(int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v] == 0) {
                par[v] = u;
                if (dfs(v)) return true;
            } else if (vis[v] == 1) {
                if (trivial || (par[u] != v && u != v)) {
                    end = u;
                    start = v;
                    return true;
                }
            }
        }
        vis[u] = 2;
        return false;
    }
    vector<int> get_cycle() {
        vis.assign(n, 0);
        par.assign(n, -1);
        for (int v = 0; v < n; v++)
            if (vis[v] == 0 && dfs(v)) break;
        vector<int> cycle;
        if (start != -1) {
            cycle.emplace_back(start);
            for (int v = end; v != start; v = par[v]) cycle.emplace_back(v);
            cycle.emplace_back(start);
            reverse(cycle.begin(), cycle.end());
        }
        return cycle;
    }
} finder;

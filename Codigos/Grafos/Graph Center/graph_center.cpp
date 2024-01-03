const int INF = 1e9 + 9;

vector<vector<int>> adj;

struct GraphCenter {
    int n, diam = 0;
    vector<int> centros, dist, pai;
    int bfs(int s) {
        queue<int> q;
        q.push(s);
        dist.assign(n +5, INF);
        pai.assign(n + 5, -1);
        dist[s] = 0;
        int maxidist = 0, maxinode = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] >= maxidist) { maxidist = dist[u], maxinode = u; }
            for (int v : adj[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pai[v] = u;
                    q.push(v);
                }
            }
        }
        diam = max(diam, maxidist);
        return maxinode;
    }
    GraphCenter(int st = 0) : n(adj.size()) {
        int d1 = bfs(st);
        int d2 = bfs(d1);
        vector<int> path;
        for (int u = d2; u != -1; u = pai[u]) { path.push_back(u); }
        int len = path.size();
        if (len % 2 == 1) {
            centros.push_back(path[len / 2]);
        } else {
            centros.push_back(path[len / 2]);
            centros.push_back(path[len / 2 - 1]);
        }
    }
};

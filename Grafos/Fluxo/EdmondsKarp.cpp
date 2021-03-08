struct EdmondsKarp {
    const int INF = 1e9;
    int n, s, t;
    vector <vector <int> > adj, cap;

    int vistoken = 1;
    vector<int> visto;

    EdmondsKarp(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>(0));
        cap.assign(n, vector<int>(n, -1));
    } 

    void addEdge(int a, int b, int c) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
        cap[b][a] = 0;
    }

    int bfs() {
        queue <int> fila;
        fila.push(s);
        vector <int> pai(n, -1);
        while (!fila.empty()) {
            int n = fila.front();
            if (n == t) break;
            fila.pop();
            visto[n] = vistoken;
            for (int i : adj[n]) {
                if (visto[i] != vistoken && cap[n][i] > 0) {
                    fila.push(i);
                    pai[i] = n;
                }
            }
        }
        if (pai[t] == -1) return 0;
        int f = INF;
        for (int i = t; i != s; i = pai[i]) {
            f = min(f, cap[pai[i]][i]);
        }
        for (int i = t; i != s; i = pai[i]) {
            cap[pai[i]][i] -= f;
            cap[i][pai[i]] += f;
        }
        return f;
    }

    int flow() {
        visto.assign(n, 0);
        int maxflow = 0;
        for (int f = bfs(); f != 0; f = bfs()) {
            maxflow += f;
            vistoken++;
        }
        return maxflow;
    }
};

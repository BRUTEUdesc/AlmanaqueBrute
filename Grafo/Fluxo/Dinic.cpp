#define INF 1e9

typedef vector <int> vi;

int n, s, t;

vector <vi> adj, cap;
vi level, prox;

bool bfs() {
    level.assign(n, -1);
    queue <int> fila;
    fila.push(s);
    level[s] = 0;

    while (!fila.empty()) {
        int n = fila.front();
        fila.pop();

        for (int i : adj[n]) {
            if (level[i] == -1 && cap[n][i] > 0) {
                level[i] = level[n] + 1;
                fila.push(i);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int n, int mi) {
    if (n == t) return mi;
    for (; prox[n] < adj[n].size(); prox[n]++) {
        int i = adj[n][prox[n]];
        if (level[i] == level[n]+1 && cap[n][i] > 0) {
            int f = dfs(i, min(mi, cap[n][i]));

            if (f != 0) {
                cap[n][i] -= f;
                cap[i][n] += f;
                return f;
            }
        }
    }
    return 0;
}

// Dinic
// runs on O(V²E) and O(sqrt(V)*E) on bipartite graphs
int main() {
    // Variables to inicialize
    // n = Number of nodes
    // s = Start Node
    // t = Sink Node

    adj.assign(n, vi(0));
    cap.assign(n, vi(n, 0));

    int maxflow = 0;
    while (bfs()) {
        prox.assign(n, 0);
        for (int f = dfs(s, INF); f != 0; f = dfs(s, INF)) maxflow += f;
    }

    cout << maxflow << endl;

}

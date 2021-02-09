#define INF 1e9

typedef vector <int> vi;

int n, s, t;

vector <vi> adj, cap;

int vistoken = 1;
vi visto;

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

// EdmondsKarp
// Runs in O(V*E²)
int main() {
    // Variables to inicialize
    // n = Number of nodes
    // s = Start Node
    // t = Sink Node

    adj.assign(n, vi(0));
    cap.assign(n, vi(n, -1));

    visto.assign(n, 0);

    int maxflow = 0;
    for (int f = bfs(); f != 0; f = bfs()) {
        maxflow += f;
        vistoken++;
    }

    cout << maxflow << endl;
}

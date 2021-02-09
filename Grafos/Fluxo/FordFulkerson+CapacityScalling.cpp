#define INF 1e9

typedef vector <int> vi;

vector <vi> adj;
vector <vi> cap;

int vistoken = 1;
vi visto;

int n, s, t;

int delta;
int dfs(int n, int mi) {
    if (n == t) return mi;
    visto[n] = vistoken;

    for (int i : adj[n]) {
        if (visto[i] != vistoken && cap[n][i] >= delta) {
            int f = dfs(i, min(mi, cap[n][i]));

            if (f > 0) {
                cap[n][i] -= f;
                cap[i][n] += f;
                return f;
            }
        }
    }

    return 0;
}

// Ford Fulkerson + Capacity Scalling
// Runs on O(E*log(U))
int main() {
    // Variables to inicialize
    // n = Number of nodes
    // s = Start Node
    // t = Sink Node

    int u = 0; // Greatest vertex weight on graph

    adj.assign(n, vi(0));
    cap.assign(n, vi(n, 0));

    delta = pow(2, floor(log2(u)));
    
    visto.assign(n, 0);

    int maxflow = 0;
    for (; delta > 0; delta /= 2) {
        vistoken++;
        for (int f = dfs(s, INF); f != 0; f = dfs(s, INF)) {
            vistoken++;
            maxflow += f;
        }
    }

    cout << maxflow << endl;
}

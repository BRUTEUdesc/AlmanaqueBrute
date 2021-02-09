# define INF 1e9

typedef vector <int> vi;

int n, s, t;

vector <vi> adj, cap, cost;
vi pai, dis;

bool spfa() {
    pai.assign(n, -1);
    dis.assign(n, INF);

    vector <bool> inq(n, 0);
    queue <int> fila;

    fila.push(s);
    dis[s] = 0;
    inq[s] = 1;

    while (!fila.empty()) {
        int n = fila.front();
        fila.pop();

        inq[n] = false;
        for (int i : adj[n]) {
            if (cap[n][i] > 0 && dis[n] + cost[n][i] < dis[i]) {
                dis[i] = dis[n] + cost[n][i];
                pai[i] = n;
                if (!inq[i]) {
                    inq[i] = true;
                    fila.push(i);
                }
            }
        }
    }
    return pai[t] != -1;
}

int main() {
    // Variables to inicialize
    // n = Number of nodes
    // s = Start Node
    // t = Sink Node

    adj.assign(n, vi(0));
    cap.assign(n, vi(n, -1));
    cost.assign(n, vd(n, -1));

    int maxflow = 0, mincost = 0;
    while (spfa()) {
        int f = INF;
        for (int i = t; i != s; i = pai[i]) {
            f = min(f, cap[pai[i]][i]);
            mincost += cost[pai[i]][i];
        }
        maxflow += f;

        for (int i = t; i != s; i = pai[i]) {
            cap[pai[i]][i] -= f;
            cap[i][pai[i]] += f;
        }
    }

    cout << mincost << endl;
}

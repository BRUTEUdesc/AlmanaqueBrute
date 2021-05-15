const long long INF = 1e18;

struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};

struct MinCostMaxFlow {
    int n, s, t, m = 0;
    long long maxflow = 0, mincost = 0;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;

    MinCostMaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
    }

    void add_edge(int u, int v, long long cap, long long cost) {
        edges.emplace_back(u, v, cap, cost);
        edges.emplace_back(v, u, 0, -cost);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }

    bool spfa() {
        vector <int> pego(n, -1);
        vector <long long> dis(n, INF);
        vector <bool> inq(n, false);
        queue <int> fila;
        fila.push(s);
        dis[s] = 0;
        inq[s] = 1;
        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1) continue;
                int v = edges[id].v;
                if (dis[v] > dis[u] + edges[id].cost) {
                    dis[v] = dis[u] + edges[id].cost;
                    pego[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        fila.push(v);
                    }
                }
            }
        }

        if (pego[t] == -1) return 0;
        long long f = INF;
        for (int id = pego[t]; id != -1; id = pego[edges[id].u]) {
            f = min(f, edges[id].cap - edges[id].flow);
            mincost += edges[id].cost;
        }
        for (int id = pego[t]; id != -1; id = pego[edges[id].u]) {
            edges[id].flow += f;
            edges[id ^ 1].flow -= f;
        }
        maxflow += f;
        return 1;
    }

    long long flow() {
        while (spfa());
        return maxflow;
    }
};

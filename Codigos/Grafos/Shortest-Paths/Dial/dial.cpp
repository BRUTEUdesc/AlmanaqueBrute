const int N = 1e5 + 5;
const int INF = 1e9;
const int D = 61;

int n;
vector<pair<int, int>> adj[N];

vector<int> dial(int s) {
    vector<int> dist(n, INF);
    vector<basic_string<int>> q(D);
    dist[s] = 0;
    q[0].push_back(s);

    int prev = -1;
    while(true) {
        int x = -1;
        for(int i = 1; i <= D; i++) {
            int cur = (prev + i) % D;
            if(not q[cur].empty()) {
                x = cur;
                break;
            }
        }
        if(x == -1) break;
        prev = x;

        while(not q[x].empty()) {
            int u = q[x].back();
            q[x].pop_back();
            if(x != dist[u] % D) continue;

            for(auto [w, v] : adj[u]) {
                int d = dist[u] + w;
                if(d < dist[v]) {
                    q[d % D].push_back(v);
                    dist[v] = d;
                }
            }
        }
    }
    return dist;
}

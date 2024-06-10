const int N = 3e3 + 5;
const ll INF = 1e18;
int n;

ll adj[N][N]; // adj[u][v] = peso da aresta u-v, INF se não existe
ll dist[N][N];

void floydwarshall() {
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) dist[u][v] = adj[u][v];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}
typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;

vii adj[MAX];

#define INF 1e9+9
int dist[MAX];

int dijkstra(int s, int f){
    for(int i=1;i<=n; i++) dist[i] = INF;

    set<ii> pq;
    dist[s] = 0;
    pq.insert(ii(0,s));

    while(!pq.empty()){

        int u = pq.begin()->second;
        pq.erase(pq.begin());

        for(int i=0; i<(int)adj[u].size(); i++){

            int v = adj[u][i].second;
            int w = adj[u][i].first;

            if(dist[v] > dist[u] + w){

                pq.erase(ii(dist[v],v));
                dist[v] = dist[u]+w;
                pq.insert(ii(dist[v],v));
            }
        }
    }

    return dist[f];
}
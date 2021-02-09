typedef vector<int> vi;
typedef vector<vi> mat;
#define MAX 2000
#define UNV -1
#define pb push_back

int num[MAX], low[MAX], parent[MAX], counter=0, rootChildren, articulatio;
int cont = 0;
mat adj;

void tarjan(int u){
    low[u] = num[u] = counter++;
    for (int i=0, v; i<(int)adj[u].size(); i++){
        v = adj[u][i];
        if (num[v] == UNV){
            parent[v] = u;
            tarjan(v);  
            if (low[v] > num[u]) 
                cont++;
            low[u] = min(low[u], low[v]);
        }
        else if (v != parent[u]){
            low[u] = min(low[u], low[v]);
        }
    }
}

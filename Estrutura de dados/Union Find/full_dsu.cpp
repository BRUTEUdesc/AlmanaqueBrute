// DSU com capacidade de adicionar e remover vértices;
// EXTREMAMENTE PODEROSO
// Funciona de maneira off-line, vá adicionando as operações e receba as respostas das consultas no retorno da função run
// O(m*log(m)*log(n)) onde m é o  número de queries e n é o número de nodos
// ***** POSSIVELMETE INSTAVEL!! *****  (WA em alguns exercícios porém AC em outros)

struct full_dsu{
    struct change{ int node, old_size;};
    struct query { int l, r, u, v, type;};
    stack<change> changes;
    map<pair<int,int>, vector<query>> edges;
    vector<query> queries;
    vector<int> parent, size;
    int number_of_sets, time;
    
    full_dsu(int n){
        time = 0;
        size.resize(n+5, 1);
        number_of_sets = n;
        loop(i, 0, n+5) parent.push_back(i);
    }
    
    int get(int a){ return (parent[a] == a? a: get(parent[a]));}
    bool same(int a, int b){return get(a) == get(b);}
    void checkpoint(){changes.push({-2, 0});}
    
    void join(int a, int b){
        a = get(a); b = get(b);
        if(a == b) return;   
        if(size[a] > size[b]) swap(a, b);
        changes.push({a, size[b]});
        parent[a] = b;
        size[b] += size[a];
        --number_of_sets;
    }
    
    void rollback(){
        while(!changes.empty()){
            auto ch = changes.top();
            changes.pop();
            if(ch.node == -2) break;
            size[parent[ch.node]] = ch.old_size;
            parent[ch.node] = ch.node;  
            ++number_of_sets;
        }
    }
    
    void ord(int& a, int& b){if(a > b) swap(a, b);}
    void add(int u, int v){ ord(u, v); edges[{u, v}].push_back({time++, (int)1e9, u, v, 0});}
    void remove(int u, int v){ ord(u, v); edges[{u, v}].back().r = time++;}
    void question(int u, int v){ ord(u, v); queries.push_back({time, time, u, v, 1}); ++time;} // consulta com nodo 
    void question(){ queries.push_back({time, time, 0, 0, 1}); ++time;} // consulta sem nodo
    
    vector<int> solve(){
        for(auto [p, v]: edges) for(auto q: v) queries.push_back(q);
        vector<int> vec(time, -1), ans;
        run(queries, 0, time, vec);
        for(int i: vec) if(i != -1) ans.push_back(i);
        return ans;
    }
    
    void run(vector<query>& qrs, int l, int r, vector<int>& ans){
        if(l > r) return;
        if(l == r){
            for(auto q: qrs) if(q.type && q.l == l) ans[l] = same(q.u, q.v); // ou ans[l] = number_of_sets; 
            return;
        }
        checkpoint();
        vector<query> qrs_aux;
        for(auto q: qrs){
            if (!q.type && q.l <= l && r <= q.r) join(q.u, q.v);
            else if (r < q.l || l > q.r) continue;
            else qrs_aux.push_back(q);
        }
        int m = (l+r)/2;
        run(qrs_aux, l, m, ans);
        run(qrs_aux, m+1, r, ans);
        rollback();
    }
};
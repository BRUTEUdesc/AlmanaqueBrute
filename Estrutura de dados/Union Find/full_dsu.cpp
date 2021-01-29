// DSU com capacidade de adicionar e remover vértices;
// EXTREMAMENTE PODEROSO
// Funciona de maneira off-line, vá adicionando as operações e receba as respostas das consultas no retorno da função run
// O(m*log(m)*log(n)) onde m é o  número de queries e n é o número de nodos

struct full_dsu{
    #define LIM (int)1e6+5
    struct change{ int node, old_size;};
    struct query{ int l, r, u, v, type;};
    stack<change> changes;
    map<pair<int,int>, query> edges;
    vector<query> queries;
    vector<int> parent, size;
    int number_of_sets, time;
    
    full_dsu(int n){
        time = 0;
        size.resize(n+5, 1);
        number_of_sets = n;
        changes.push({-2, 0});
        for(int i = 0; i < n+5; ++i) parent.push_back(i);
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
        while(1){
            auto ch = changes.top();
            changes.pop();
            if(ch.node == -2) break;
            size[parent[ch.node]] = ch.old_size;
            parent[ch.node] = ch.node;
            ++number_of_sets;
        }
    }
    
    void ord(int& a, int& b){if(a > b) swap(a, b);}
    void add(int u, int v){ ord(u, v); edges[{u, v}] = {time++, LIM, u, v, 0};}
    void remove(int u, int v){ ord(u, v); edges[{u, v}].r = time++;}
    // void question(int u, int v){ ord(u, v); queries.push_back({time, time, u, v, 1}); ++time;} // consulta com nodo 
    void question(){queries.push_back({time, time, 0, 0, 1}); ++time;} // consulta sem nodo
    
    vector<int> run(){ // essa é a função que retorna as respostas
        for(auto [p, q]: edges) queries.push_back(q);
        vector<int> vec(time, -1), ans;
        work(queries, 0, time, vec);
        for(int i: vec) if(i != -1) ans.push_back(i);
        return ans;
    }
    
    void work(vector<query>& qrs, int l, int r, vector<int>& vec){
        if(l > r) return;
        if(l == r){
            for(auto q: qrs) if(q.type == 1 && q.l == l) vec[l] = number_of_sets; // escolher qual função chamar para responder
            return;
        }
        checkpoint();
        vector<query> qrs_aux;
        for(auto q: qrs){
            if(q.type == 0 && l >= q.l && r <= q.r) join(q.u, q.v);
            if((q.type == 1 && l <= q.l && r >= q.l) || (q.type == 0 && ((l <= q.l && r >= q.l) || (l <= q.r && r >= q.r))))
                qrs_aux.push_back(q);
        }
        int m = (l+r)/2;
        work(qrs_aux, l, m, vec);
        work(qrs_aux, m+1, r, vec);
        rollback();
    }
};

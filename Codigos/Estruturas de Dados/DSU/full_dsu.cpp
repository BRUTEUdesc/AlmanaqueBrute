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
    
    // consulta se os vértices estão no mesmo grupo
    void question(int u, int v){ ord(u, v); queries.push_back({time, time, u, v, 1}); ++time;}
    
    // consulta a quantidade de grupos distintos
    void question(){ queries.push_back({time, time, 0, 0, 1}); ++time;}
    
    vector<int> solve(){
        for(auto [p, v]: edges) queries.insert(queries.end(), all(v));
        vector<int> vec(time, -1), ans;
        run(queries, 0, time, vec);
        for(int i: vec) if(i != -1) ans.push_back(i);
        return ans;
    }
    
    void run(const vector<query>& qrs, int l, int r, vector<int>& ans){
        if(l > r) return;
        checkpoint();
        vector<query> qrs_aux;
        for(auto& q: qrs){
            if (!q.type && q.l <= l && r <= q.r) join(q.u, q.v); 
            else if (r < q.l || l > q.r) continue;
            else qrs_aux.push_back(q);
        }
        if(l == r){
            for(auto& q: qrs) if(q.type && q.l == l){
                ans[l] = number_of_sets; // número de grupos nesse tempo
                // ans[l] = same(q.u, q.v); // se u e v estão no mesmo grupo
            }
            rollback();
            return;
        }
        int m = (l+r)/2;
        run(qrs_aux, l, m, ans);
        run(qrs_aux, m+1, r, ans);
        rollback();
    }
};

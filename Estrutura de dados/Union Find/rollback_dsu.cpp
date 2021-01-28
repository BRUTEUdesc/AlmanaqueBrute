// DSU com rollback, desfaz as últimas K uniões em O(K);
// O rollback não altera a complexidade, uma vez K <= queries.
// Só funciona sem compressão de caminho!! 
// Join, Get e Same em O(log(N))

struct rollback_dsu{
    struct change{ int node, old_size;};
    stack<change> changes;
    vector<int> parent, size;
    int number_of_sets;
    rollback_dsu(int n){
        size.resize(n+5, 1);
        number_of_sets = n;
        for(int i = 0; i < n+5; ++i) parent.push_back(i);
    }
    
    int get(int a){
        while(a != parent[a]) a = parent[a];
        return a;
    }
    
    bool same(int a, int b){return get(a) == get(b);}
    
    void join(int a, int b){
        a = get(a); b = get(b);
        if(a == b) {
            changes.push({-1, -1});
            return;   
        }
        if(size[a] > size[b]) swap(a, b);
        changes.push({a, size[b]});
        parent[a] = b;
        size[b] += size[a];
        --number_of_sets;
    }
    
    void rollback(int qnt){
        for(int i = 0; i < qnt; ++i){
            auto ch = changes.top();
            if(ch.node == -1) {
                changes.pop();
                continue;
            }
            size[parent[ch.node]] = ch.old_size;
            parent[ch.node] = ch.node;
            changes.pop();
            ++number_of_sets;
        }
    }
};

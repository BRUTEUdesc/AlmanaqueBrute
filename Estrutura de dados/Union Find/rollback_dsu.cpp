// DSU com rollback, retorna as últimas K operações em O(K);
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
        loop(i, 0, n+5) parent.push_back(i);
    }
    
    int get(int a){
        while(a != parent[a]) a = parent[a];
        return a;
    }
    
    bool same(int a, int b){return get(a) == get(b);}
    
    void join(int a, int b){
        a = get(a); b = get(b);
        if(a == b) return;
        if(size[a] > size[b]) swap(a, b);
        changes.push({a, size[b]});
        parent[a] = b;
        size[b] += size[a];
        --number_of_sets;
    }
    
    void rollback(int qnt){
        loop(i, 0, qnt){
            auto ch = changes.top();
            size[parent[ch.node]] = ch.old_size;
            parent[ch.node] = ch.node;
            changes.pop();
            ++number_of_sets;
        }
    }
    
};

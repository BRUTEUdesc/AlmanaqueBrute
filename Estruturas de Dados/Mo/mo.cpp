int block_sz; // Better if 'const';

namespace mo{
    struct query {
        int l, r, idx;
        bool operator<(query q) const {
            return make_pair(l / block_sz, r) < make_pair(q.l / block_sz, q.r);
        }
    };
    vector<query> queries;    
    
    mo(int n){
        block_sz = (int) sqrt(n);
        // TODO: initialize data structure        
    }
    void add_query(int l, int r){
        queries.push_back({l, r, (int) queries.size()});
    }
    void remove(int idx){
        // TODO: remove value at idx from data structure
    }
    void add(int idx){
        // TODO: add value at idx from data structure
    }
    int get_answer(){
        // TODO: extract the current answer of the data structure
        return 0;
    }

    vector<int> mo_s_algorithm() {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());
        int L = 0;
        int R = -1;
        for (query q : queries) {
            while (L > q.l) L--, add(L);
            while (R < q.r) R++, add(R);
            while (L < q.l) remove(L), L++;
            while (R > q.r) remove(R), R--;
            answers[q.idx] = get_answer();
        }
        return answers;
    }
    
};

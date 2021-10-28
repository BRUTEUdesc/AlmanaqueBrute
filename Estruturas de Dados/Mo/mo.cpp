typedef pair<int, int> ii;
int block_sz; // Better if 'const';

namespace mo{
    struct query {
        int l, r, idx;
        bool operator<(query q) const {
            int _l  = l/block_sz;
            int _ql = q.l/block_sz;
            return ii(_l, (_l&1? -r: r)) < ii(_ql, (_ql&1? -q.r: q.r));
        }
    };
    vector<query> queries;    
    
    void build(int n){
        block_sz = (int) sqrt(n);
        // TODO: initialize data structure        
    }
    inline void add_query(int l, int r){
        queries.push_back({l, r, (int) queries.size()});
    }
    inline void remove(int idx){
        // TODO: remove value at idx from data structure
    }
    inline void add(int idx){
        // TODO: add value at idx from data structure
    }
    inline int get_answer(){
        // TODO: extract the current answer of the data structure
        return 0;
    }

    vector<int> run() {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());
        int L = 0;
        int R = -1;
        for (query q : queries) {
            while (L > q.l) add(--L);
            while (R < q.r) add(++R);
            while (L < q.l) remove(L++);
            while (R > q.r) remove(R--);
            answers[q.idx] = get_answer();
        }
        return answers;
    }
    
};

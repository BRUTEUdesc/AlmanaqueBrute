
namespace parallel_binary_search {
    typedef tuple<int, int, long long, long long> query; //{value, id, l, r}
    vector<query> queries[1123456];                      // pode ser um mapa se
                                                         // for muito esparso
    long long ans[1123456];                              // definir pro tamanho
                                                         // das queries
    long long l, r, mid;
    int id = 0;
    void set_lim_search(long long n) {
        l = 0;
        r = n;
        mid = (l + r) / 2;
    }

    void add_query(long long v) {
        queries[mid].push_back({v, id++, l, r});
    }

    void advance_search(long long v) {
        // advance search
    }

    bool satisfies(long long mid, int v, long long l, long long r) {
        // implement the evaluation
    }

    bool get_ans() {
        // implement the get ans
    }

    void parallel_binary_search(long long l, long long r) {

        bool go = 1;
        while (go) {
            go = 0;
            int i = 0; // outra logica se for usar
                       // um mapa
            for (auto &vec : queries) {
                advance_search(i++);
                for (auto q : vec) {
                    auto [v, id, l, r] = q;
                    if (l > r) {
                        continue;
                    }
                    go = 1;
                    // return while satisfies
                    if (satisfies(i, v, l, r)) {
                        ans[i] = get_ans();
                        long long mid = (i + l) / 2;
                        queries[mid] = query(v, id, l, i - 1);
                    } else {
                        long long mid = (i + r) / 2;
                        queries[mid] = query(v, id, i + 1, r);
                    }
                }
                vec.clear();
            }
        }
    }

} // namespace name

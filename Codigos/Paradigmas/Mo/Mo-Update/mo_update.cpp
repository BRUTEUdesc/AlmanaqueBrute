typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
int block_sz; // Better if 'const';
vector<int> vec;
namespace mo {
    struct query {
        int l, r, t, idx;
        bool operator<(query q) const {
            int _l = l / block_sz;
            int _r = r / block_sz;
            int _ql = q.l / block_sz;
            int _qr = q.r / block_sz;
            return iii(_l, _l & 1 ? -_r : _r, _r & 1 ? t : -t) <
                   iii(_ql, _ql & 1 ? -_qr : _qr, _qr & 1 ? q.t : -q.t);
        }
    };
    vector<query> queries;
    vector<ii> updates;

    void build(int n) {
        block_sz = pow(1.4142 * n, 2.0 / 3);
        // TODO: initialize data structure
    }
    inline void add_query(int l, int r) {
        queries.push_back({l, r, (int)updates.size(), (int)queries.size()});
    }
    inline void add_update(int x, int v) { updates.push_back({x, v}); }
    inline void remove(int idx) {
        // TODO: remove value at idx from data
        // structure
    }
    inline void add(int idx) {
        // TODO: add value at idx from data
        // structure
    }
    inline void update(int l, int r, int t) {
        auto &[x, v] = updates[t];
        if (l <= x && x <= r) remove(x);
        swap(vec[x], v);
        if (l <= x && x <= r) add(x);
    }
    inline int get_answer() {
        // TODO: extract the current answer from
        // the data structure
        return 0;
    }

    vector<int> run() {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());
        int L = 0;
        int R = -1;
        int T = 0;
        for (query q : queries) {
            while (T < q.t) update(L, R, T++);
            while (T > q.t) update(L, R, --T);
            while (L > q.l) add(--L);
            while (R < q.r) add(++R);
            while (L < q.l) remove(L++);
            while (R > q.r) remove(R--);
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};

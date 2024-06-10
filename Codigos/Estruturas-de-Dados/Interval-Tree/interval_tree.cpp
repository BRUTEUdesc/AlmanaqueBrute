#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct interval {
    long long lo, hi, id;
    bool operator<(const interval &i) const {
        return tuple(lo, hi, id) < tuple(i.lo, i.hi, i.id);
    }
};

const long long INF = 1e18;

template <class CNI, class NI, class Cmp_Fn, class Allocator>
struct intervals_node_update {
    typedef long long metadata_type;
    int sz = 0;
    virtual CNI node_begin() const = 0;
    virtual CNI node_end() const = 0;
    inline vector<int> overlaps(const long long l, const long long r) {
        queue<CNI> q;
        q.push(node_begin());
        vector<int> vec;
        while (!q.empty()) {
            CNI it = q.front();
            q.pop();
            if (it == node_end()) continue;
            if (r >= (*it)->lo && l <= (*it)->hi) vec.push_back((*it)->id);
            CNI l_it = it.get_l_child();
            long long l_max = (l_it == node_end()) ? -INF : l_it.get_metadata();
            if (l_max >= l) q.push(l_it);
            if ((*it)->lo <= r) q.push(it.get_r_child());
        }
        return vec;
    }
    inline void operator()(NI it, CNI end_it) {
        const long long l_max =
            (it.get_l_child() == end_it) ? -INF : it.get_l_child().get_metadata();
        const long long r_max =
            (it.get_r_child() == end_it) ? -INF : it.get_r_child().get_metadata();
        const_cast<long long &>(it.get_metadata()) = max((*it)->hi, max(l_max, r_max));
    }
};
typedef tree<interval, null_type, less<interval>, rb_tree_tag, intervals_node_update>
    interval_tree;

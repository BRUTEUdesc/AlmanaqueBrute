#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct interval{
    ll lo, hi, id;
    bool operator <(const interval& i) const{
        return lo < i.lo || (lo == i.lo && hi < i.hi) || (lo == i.lo && hi == i.hi && id < i.id);
    }
};
template<class CNI, class NI, class Cmp_Fn, class Allocator>
struct intervals_node_update{
    typedef ll metadata_type;
    int sz = 0;
    virtual CNI node_begin() const = 0;
    virtual CNI node_end() const = 0;
    
    inline vector<int> overlaps(const ll l, const ll r){
        queue<CNI> q; q.push(node_begin());
        vector<int> vec;
        while(!q.empty()){
            CNI it = q.front(); q.pop();
            if (it == node_end()) continue;
            if (r >= (*it)->lo && l <= (*it)->hi) vec.push_back((*it)->id);
            CNI l_it = it.get_l_child();
            ll l_max = (l_it == node_end())? -INF: l_it.get_metadata();
            if (l_max >= l) q.push(l_it);
            if ((*it)->lo <= r) q.push(it.get_r_child());    
        }
        return vec;
    }

    inline void operator()(NI it, CNI end_it){
        const ll l_max = (it.get_l_child() == end_it)? -INF: it.get_l_child().get_metadata();
        const ll r_max = (it.get_r_child() == end_it)? -INF: it.get_r_child().get_metadata();
        const_cast<ll&>(it.get_metadata()) = max((*it)->hi, max(l_max, r_max));
    }
};
typedef tree<interval, null_type, less<interval>, rb_tree_tag, intervals_node_update> interval_tree;

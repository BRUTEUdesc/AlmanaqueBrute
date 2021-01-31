// Capaz de retornar todos os intervalos que intersectam overlaps(l, r) [l, r]
// insert(l, r, id), erase(l, r, id) , overlap(l, r) e find(l, r, id) em O(log(n))
// é necessário inserir e apagar indicando tanto os limites quanto o id do intervalo

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct interval{
    ll lo, hi, id;
    bool operator <(const interval& i) const{
        return lo < i.lo || (lo == i.lo && hi < i.hi);
    }
};
template<class CNI, class NI, class Cmp_Fn, class Allocator>
struct intervals_node_update{
    typedef ll metadata_type;
    vector<int> vec;
    void overlaps(const interval& inter, const CNI it){
        CNI end_it = node_end();
        if (it == end_it) return;
        if (inter.hi >= (*it)->lo && inter.lo <= (*it)->hi) vec.push_back((*it)->id);
        const CNI l_it = it.get_l_child(), r_it = it.get_r_child();
        const ll l_max = (l_it == end_it)? -INF: l_it.get_metadata();
        if (l_max >= inter.lo) overlaps(inter, l_it);
        if ((*it)->lo <= inter.hi) overlaps(inter, r_it);
    }
    vector<int> overlaps(ll a, ll b){vec.clear(); overlaps({a, b}, node_begin()); return vec;}
    inline void operator()(NI it, CNI end_it){
        const ll l_max = (it.get_l_child() == end_it)? -INF: it.get_l_child().get_metadata();
        const ll r_max = (it.get_r_child() == end_it)? -INF: it.get_r_child().get_metadata();
        const_cast<ll&>(it.get_metadata()) = max((*it)->hi, max(l_max, r_max));
    }
    virtual CNI node_begin() const = 0;
    virtual CNI node_end() const = 0;
};
typedef tree<interval, null_type, less<interval>, rb_tree_tag, intervals_node_update> interval_tree;

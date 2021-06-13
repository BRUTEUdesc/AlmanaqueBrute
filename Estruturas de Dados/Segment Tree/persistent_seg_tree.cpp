// Seg Operation
ll op(ll a, ll b){ return a+b;}
ll neutral = 0;
#define mid ((L+R)/2)

struct SegTree{
        
    struct node{
        ll value;
        node *L, *R;
        node(){value = neutral; L = R = 0;}
        node(ll x){value = x; L = R = 0;}
        node(node* l, node* r): L(l), R(r){ value = op(l->value, r->value);}
        void apply(){
            if(L == 0) L = new node(), R = new node();
        }
    };
 
    ll l, r;
    vector<node*> roots;
    SegTree(int _l, int _r): l(_l), r(_r){ roots.push_back(new node());}
    void push(node* &u, int L, int R){ if(L != R) u->apply();}
 
    node* update(node* &u, int L, int R, int pos, int x){
        push(u, L, R);
        if(L == R) return new node(op(u->value, x));
        if(L <= pos && pos <= mid) return new node(update(u->L, L, mid, pos, x), u->R);
        else return new node(u->L, update(u->R, mid+1, R, pos, x));
    }
    void update(int pos, int x, bool new_node = 1){
        if(new_node) roots.push_back(update(roots.back(), l, r, pos, x));
        else roots.back() = update(roots.back(), l, r, pos, x);
    }

    int query(node* &u, int L, int R, int i, int j){
        push(u, L, R);
        if(R < i || j < L) return neutral;
        if(i <= L && R <= j) return u->value;
        int r1 = query(u->L, L, mid, i, j);
        int r2 = query(u->R, mid+1, R, i, j);
        return op(r1, r2);
    }
    int query(int cur, int i, int j){ return query(roots[cur], l, r, i, j);}
};

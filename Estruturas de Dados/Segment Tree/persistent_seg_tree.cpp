struct SegTree{
    #define op(a, b) (a+b) 
    #define neutral 0
    struct node{
        ll v = neutral;
        node *l = NULL, *r = NULL;
        node() {}
        node(ll v) : v(v) {}
        node(node* l, node* r): l(l), r(r) { v = op(l->v, r->v); }
        void apply(){
            if(l == NULL) l = new node();
			if(r == NULL) r = new node();
        }
    };
    ll ESQ, DIR;
    vector<node*> roots;
    SegTree(int ESQ, int DIR): ESQ(ESQ), DIR(DIR){ roots.push_back(new node()); }
    void push(node* u, int esq, int dir){ if(esq != dir) u->apply(); }
    node* update(node* u, int esq, int dir, int x, int v) {
        push(u, esq, dir);
        if(esq == dir) return new node(op(u->v, v));
        int mid = (esq + dir)/2;
        if(esq <= x && x <= mid) return new node(update(u->l, esq, mid, x, v), u->r);
        else return new node(u->l, update(u->r, mid+1, dir, x, v));
    }
    void update(int x, int v, bool new_node=true) {
        if(new_node) roots.push_back(update(roots.back(), ESQ, DIR, x, v));
        else roots.back() = update(roots.back(), ESQ, DIR, x, v);
    }
    int query(node* u, int esq, int dir, int i, int j) {
        push(u, esq, dir);
        if(dir < i || j < esq) return neutral;
        if(i <= esq && dir <= j) return u->v;
        int mid = (esq + dir)/2;
        int r1 = query(u->l, esq, mid, i, j);
        int r2 = query(u->r, mid+1, dir, i, j);
        return op(r1, r2);
    }
    int query(int root, int l, int r){ return query(roots[root], ESQ, DIR, l, r); }
};

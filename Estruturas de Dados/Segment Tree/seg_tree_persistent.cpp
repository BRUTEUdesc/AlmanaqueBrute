namespace seg {
    const ll ESQ = 0, DIR = 1e9+7;
	struct node {
        ll v = 0;
        node *l = NULL, *r = NULL;
        node() {}
        node(ll v) : v(v) {}
        node(node* l, node* r) : l(l), r(r) { v = l->v + r->v; }
        void apply() {
            if(l == NULL) l = new node();
            if(r == NULL) r = new node();
        }
	};
    vector <node*> roots;
    void build() { roots.push_back(new node()); }
    void push(node* n, int esq, int dir) { if (esq != dir) n->apply(); }
    // sum v on x
    node* update(node* n, int esq, int dir, int x, int v) {
        push(n, esq, dir);
        if (esq == dir) return new node(n->v + v);
        int mid = (esq + dir)/2;
        if (x <= mid) return new node(update(n->l, esq, mid, x, v), n->r);
        else return new node(n->l, update(n->r, mid+1, dir, x, v));
    }
    int update(int root, int pos, int val) {
        node* novo = update(roots[root], ESQ, DIR, pos, val);
        roots.push_back(novo);
        return roots.size() - 1;
    }
    // sum in [L, R]
    ll query(node* n, int esq, int dir, int l, int r) {
        push(n, esq, dir);
        if (esq > r || dir < l) return 0;
        if (l <= esq && dir <= r) return n->v;
        int mid = (esq + dir)/2;
        return query(n->l, esq, mid, l, r) + query(n->r, mid+1, dir, l, r);
    }
    ll query(int root, int l, int r) {
        return query(roots[root], ESQ, DIR, l, r);
    }
    // kth min number in [L, R] (l_root can not be 0)
    int kth(node* L, node* R, int esq, int dir, int k) {
        push(L, esq, dir);
        push(R, esq, dir);
        if (esq == dir) return esq;
        int mid = (esq + dir)/2;
        int cont = R->l->v - L->l->v;
        if (cont >= k) return kth(L->l, R->l, esq, mid, k);
        else return kth(L->r, R->r, mid+1, dir, k-cont);
    }
    int kth(int l_root, int r_root, int k) {
        return kth(roots[l_root-1], roots[r_root], ESQ, DIR, k);
    }
};

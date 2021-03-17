struct SegTree {
	struct nodo {
		ll v = 0;
		nodo *l = NULL, *r = NULL;
        nodo(ll v) : v(v) {}
        nodo(nodo* l, nodo* r) : l(l), r(r) {
            v = l->v + r->v;
        }
		void apply() {
			if(l == NULL) l = new nodo(0);
			if(r == NULL) r = new nodo(0);
		}
	};
    long long esq, dir;
    vector <nodo*> roots;
    SegTree(long long esq, long long dir) : esq(esq), dir(dir) {
        roots.push_back(new nodo(0));
    }
    void push(nodo* n, int esq, int dir) {
        if (esq != dir) n->apply();
    }
    // change x value to v
    nodo* update(nodo* n, int esq, int dir, int x, int v) {
        push(n, esq, dir);
        if (esq == dir) return new nodo(v);
        int mid = (esq + dir)/2;
        if (x <= mid) return new nodo(update(n->l, esq, mid, x, v), n->r);
        else return new nodo(n->l, update(n->r, mid+1, dir, x, v));
    }
    void update(int root, int pos, int val) {
        roots.push_back(update(roots[root], esq, dir, pos, val));
    }
    // kth number in [L, R]
    int kth(nodo* n, nodo* old, int esq, int dir, int k) {
        push(n, esq, dir);
        push(old, esq, dir);
        if (esq == dir) return esq;
        int mid = (esq + dir)/2;
        int cont = n->l->v - old->l->v;
        if (cont >= k) return kth(n->l, old->l, esq, mid, k);
        else return kth(n->r, old->r, mid+1, dir, k-cont);
    }
    int kth(int l_root, int r_root, int k) {
        return kth(roots[r_root], roots[l_root], esq, dir, k);
    }
};

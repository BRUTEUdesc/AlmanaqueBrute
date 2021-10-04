struct SegTree {
	struct nodo {
		long long v = 0;
		nodo *l = NULL, *r = NULL;
        nodo() {}
        nodo(long long v) : v(v) {}
        nodo(nodo* l, nodo* r) : l(l), r(r) { v = l->v + r->v; }
		void apply() {
			if(l == NULL) l = new nodo();
			if(r == NULL) r = new nodo();
		}
	};
    long long ESQ, DIR;
    vector <nodo*> roots;
    SegTree(long long esq, long long dir) : ESQ(esq), DIR(dir) {
        roots.push_back(new nodo());
    }
    void push(nodo* n, int esq, int dir) {if (esq != dir) n->apply();}
    void copy(int root) {roots.push_back(roots[root]);}
    // change x value to v
    nodo* update(nodo* n, int esq, int dir, int x, int v) {
        push(n, esq, dir);
        if (esq == dir) return new nodo(v);
        int mid = (esq + dir)/2;
        if (x <= mid) return new nodo(update(n->l, esq, mid, x, v), n->r);
        else return new nodo(n->l, update(n->r, mid+1, dir, x, v));
    }
    void update(int root, int pos, int val, bool new_node=true) {
        nodo* novo = update(roots[root], ESQ, DIR, pos, val);
        if (new_node) roots.push_back(novo);
        else roots[root] = novo;
    }
    // sum in [L, R]
    long long query(nodo* n, int esq, int dir, int l, int r) {
        push(n, esq, dir);
        if (esq > r || dir < l) return 0;
        if (l <= esq && dir <= r) return n->v;
        int mid = (esq + dir)/2;
        return query(n->l, esq, mid, l, r) + query(n->r, mid+1, dir, l, r);
    }
    long long query(int root, int l, int r) {
        return query(roots[root], ESQ, DIR, l, r);
    }
    // kth max number in [L, R]
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
        return kth(roots[r_root], roots[l_root], ESQ, DIR, k);
    }
};

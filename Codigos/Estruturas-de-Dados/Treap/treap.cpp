mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace treap {
    struct node_info {
        node_info *l, *r;
        int x, y, size;
        node_info() { }
        node_info(int x) : l(0), r(0), x(x), y(rng()), size(0) { }
    };
    using node = node_info *;
    node root = 0;
    bool setify = false;
    inline int size(node t) { return t ? t->size : 0; }
    inline void upd_size(node t) {
        if (t) t->size = size(t->l) + size(t->r) + 1;
    }
    void merge(node &t, node L, node R) {
        if (!L || !R) {
            t = L ? L : R;
        } else if (L->y > R->y) {
            merge(L->r, L->r, R);
            t = L;
        } else {
            merge(R->l, L, R->l);
            t = R;
        }
        upd_size(t);
    }
    void split(node t, int x, node &L, node &R) {
        if (!t) {
            L = R = 0;
        } else if (t->x <= x) {
            split(t->r, x, t->r, R);
            L = t;
        } else {
            split(t->l, x, L, t->l);
            R = t;
        }
        upd_size(t);
    }
    void insert(node &t, node to) {
        if (!t) {
            t = to;
        } else if (to->y > t->y) {
            split(t, to->x, to->l, to->r);
            t = to;
        } else {
            insert(to->x < t->x ? t->l : t->r, to);
        }
        upd_size(t);
    }
    bool remove(node &t, int x) {
        if (!t) return false;
        if (x == t->x) {
            node rem = t;
            merge(t, t->l, t->r);
            upd_size(t);
            delete rem;
            return true;
        }
        bool ok = remove(x < t->x ? t->l : t->r, x);
        upd_size(t);
        return ok;
    }
    bool find(node &t, int x) {
        return t ? (t->x == x || find(x < t->x ? t->l : t->r, x)) : false;
    }
    bool find(int x) { return find(root, x); }
    inline void insert(int x) {
        if (setify) {
            if (find(x)) return;
        }
        insert(root, new node_info(x));
    }
    inline void remove(int x) { remove(root, x); }
}

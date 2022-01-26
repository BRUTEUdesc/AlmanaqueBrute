struct Line{
    long long a, b;
    long long get(long long v) {return a*v + b;}
};

Line tree[4*MAX];

int le(int n) {return 2*n+1;}
int ri(int n) {return 2*n+2;}

void update(int n, int esq, int dir, Line &l){
    ll a = l.get(esq), b = l.get(dir);
    ll c = tree[n].get(esq), d = tree[n].get(dir);
    if(a >= c and b >= d) return;
    if(a <= c and b <= d) tree[n] = l;
    else {
        int mid = (esq+dir)/2;
        update(le(n), esq, mid, l);
        update(ri(n), mid+1, dir, l);
    }
}
void update(Line &l){ update(0, 0, MAX, l);}

ll query(int u, int esq, int dir, int x){
    ll res = tree[u].get(x);
    if(esq == dir) return res;
    int mid = (esq+dir)/2;
    if(x <= mid) return min(res, query(le(u), esq, mid, x));
    else           return min(res, query(ri(u), mid+1, dir, x));
}
ll query(int x){return query(0, 0, MAX, x);}

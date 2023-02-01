const int SEGMAX = 8e6+5; // should be Q * log(DIR-ESQ+1)
const ll ESQ = 0, DIR = 1e9+7;

struct seg {
	ll tree[SEGMAX];
    int R[SEGMAX], L[SEGMAX], ptr = 2; // 0 is NULL; 1 is First Root
    ll op(ll a, ll b) {
      return (a + b) % MOD;
    }
	int le(int i){
		if (L[i] == 0) L[i] = ptr++;
		return L[i];
	}
	int ri(int i){
		if (R[i] == 0) R[i] = ptr++;
		return R[i];
	}
	ll query(ll l, ll r, int n=1, ll esq=ESQ, ll dir=DIR) {
		if (r < esq || dir < l) return 0;
		if (l <= esq && dir <= r) return tree[n];
		ll mid = (esq + dir)/2;
		return op(query(l, r, le(n), esq, mid), query(l, r, ri(n), mid+1, dir));
	}
	void update(ll x, ll v, int n=1, ll esq=ESQ, ll dir=DIR) {
		if (esq == dir) tree[n] = (tree[n] + v) % MOD;
        else {
            ll mid = (esq + dir)/2;
            if (x <= mid) update(x, v, le(n), esq, mid);
            else update(x, v, ri(n), mid+1, dir);
            tree[n] = op(tree[le(n)], tree[ri(n)]); 
        }
	}
};

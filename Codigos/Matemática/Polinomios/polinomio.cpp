struct poly {
  vector<mint> a;
  inline void normalize() {
    while((int)a.size() && a.back() == 0) a.pop_back();
  }
  template<class...Args> poly(Args...args): a(args...) { }
  poly(const initializer_list<mint> &x): a(x.begin(), x.end()) { }
  int size() const { return (int)a.size(); }
  inline mint coef(const int i) const { return (i < a.size() && i >= 0) ? a[i]: mint(0); }
  mint operator[](const int i) const { return (i < a.size() && i >= 0) ? a[i]: mint(0); } //Beware!! p[i] = k won't change the value of p.a[i]
  bool is_zero() const {
    for (int i = 0; i < size(); i++) if (a[i] != 0) return 0;
    return 1;
  }
  poly operator + (const poly &x) const {
    int n = max(size(), x.size());
    vector<mint> ans(n);
    for(int i = 0; i < n; i++) ans[i] = coef(i) + x.coef(i);
    while ((int)ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
  poly operator - (const poly &x) const {
    int n = max(size(), x.size());
    vector<mint> ans(n);
    for(int i = 0; i < n; i++) ans[i] = coef(i) - x.coef(i);
    while ((int)ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
  poly operator * (const poly& b) const {
    if(is_zero() || b.is_zero()) return {};
    vector<mint> ans = multiply(a, b.a);
    while ((int)ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
  poly operator * (const mint& x) const {
    int n = size();
    vector<mint> ans(n);
    for(int i = 0; i < n; i++) ans[i] = a[i] * x;
    return ans;
  }
  poly operator / (const mint &x) const{ return (*this) * x.inv(); }
  poly& operator += (const poly &x) { return *this = (*this) + x; }
  poly& operator -= (const poly &x) { return *this = (*this) - x; }
  poly& operator *= (const poly &x) { return *this = (*this) * x; }
  poly& operator *= (const mint &x) { return *this = (*this) * x; }
  poly& operator /= (const mint &x) { return *this = (*this) / x; }
  poly mod_xk(int k) const { return {a.begin(), a.begin() + min(k, size())}; } //modulo by x^k
  poly mul_xk(int k) const { // multiply by x^k
    poly ans(*this);
    ans.a.insert(ans.a.begin(), k, 0);
    return ans;
  }
  poly div_xk(int k) const { // divide by x^k
    return vector<mint>(a.begin() + min(k, (int)a.size()), a.end());
  }
  poly substr(int l, int r) const { // return mod_xk(r).div_xk(l)
    l = min(l, size());
    r = min(r, size());
    return vector<mint>(a.begin() + l, a.begin() + r);
  }
  poly reverse_it(int n, bool rev = 0) const { // reverses and leaves only n terms
    poly ans(*this);
    if(rev) { // if rev = 1 then tail goes to head
      ans.a.resize(max(n, (int)ans.a.size()));
    }
    reverse(ans.a.begin(), ans.a.end());
    return ans.mod_xk(n);
  }
  poly differentiate() const {
    int n = size(); vector<mint> ans(n);
    for(int i = 1; i < size(); i++) ans[i - 1] = coef(i) * i;
    return ans;
  }
  poly integrate() const {
    int n = size(); vector<mint> ans(n + 1);
    for(int i = 0; i < size(); i++) ans[i + 1] = coef(i) / (i + 1);
    return ans;
  }
  poly inverse(int n) const {  // 1 / p(x) % x^n, O(nlogn)
    assert(!is_zero()); assert(a[0] != 0);
    poly ans{mint(1) / a[0]};
    for(int i = 1; i < n; i *= 2) {
      ans = (ans * mint(2) - ans * ans * mod_xk(2 * i)).mod_xk(2 * i);
    }
    return ans.mod_xk(n);
  }
  pair<poly, poly> divmod_slow(const poly &b) const { // when divisor or quotient is small
    vector<mint> A(a);
    vector<mint> ans;
    while(A.size() >= b.a.size()) {
      ans.push_back(A.back() / b.a.back());
      if(ans.back() != mint(0)) {
        for(size_t i = 0; i < b.a.size(); i++) {
          A[A.size() - i - 1] -= ans.back() * b.a[b.a.size() - i - 1];
        }
      }
      A.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return {ans, A};
  }
  pair<poly, poly> divmod(const poly &b) const { // returns quotient and remainder of a mod b
    if(size() < b.size()) return {poly{0}, *this};
    int d = size() - b.size();
    if(min(d, b.size()) < 250) return divmod_slow(b);
    poly D = (reverse_it(d + 1) * b.reverse_it(d + 1).inverse(d + 1)).mod_xk(d + 1).reverse_it(d + 1, 1);
    return {D, *this - (D * b)};
  }
  poly operator / (const poly &t) const {return divmod(t).first;}
  poly operator % (const poly &t) const {return divmod(t).second;}
  poly& operator /= (const poly &t) {return *this = divmod(t).first;}
  poly& operator %= (const poly &t) {return *this = divmod(t).second;}
  poly log(int n) const { //ln p(x) mod x^n
    assert(a[0] == 1);
    return (differentiate().mod_xk(n) * inverse(n)).integrate().mod_xk(n);
  }
  poly exp(int n) const { //e ^ p(x) mod x^n
    if(is_zero()) return {1};
    assert(a[0] == 0);
    poly ans({1});
    int i = 1;
    while(i < n) {
      poly C = ans.log(2 * i).div_xk(i) - substr(i, 2 * i);
      ans -= (ans * C).mod_xk(i).mul_xk(i);
      i *= 2;
    }
    return ans.mod_xk(n);
  }
  //better for small k, k < 100000
  poly pow(int k, int n) const { // p(x)^k mod x^n
    if(is_zero()) return *this;
    poly ans({1}), b = mod_xk(n);
    while(k) {
      if(k & 1) ans = (ans * b).mod_xk(n);
      b = (b * b).mod_xk(n);
      k >>= 1;
    }
    return ans;
  }
  int leading_xk() const { //minimum i such that C[i] > 0
    if(is_zero()) return 1000000000;
    int res = 0; while(a[res] == 0) res++;
    return res;
  }
  //better for k > 100000
  poly pow2(int k, int n) const { // p(x)^k mod x^n
    if(is_zero()) return *this;
    int i = leading_xk();
    mint j = a[i];
    poly t = div_xk(i) / j;
    poly ans = (t.log(n) * mint(k)).exp(n);
    if (1LL * i * k > n) ans = {0};
    else ans = ans.mul_xk(i * k).mod_xk(n);
    ans *= (j.pwr(j, k));
    return ans;
  }
  // if the poly is not zero but the result is zero, then no solution
  //poly sqrt(int n) const {
  //  if ((*this)[0] == mint(0)) {
  //    for (int i = 1; i < size(); i++) {
  //      if ((*this)[i] != mint(0)) {
  //        if (i & 1) return {};
  //        if (n - i / 2 <= 0) break;
  //        return div_xk(i).sqrt(n - i / 2).mul_xk(i / 2);
  //      }
  //    }
  //    return {};
  //  }
  //  mint s = (*this)[0].sqrt();
  //  if (s == 0)  return {};
  //  poly y = *this / (*this)[0];
  //  poly ret({1});
  //  mint inv2 = mint(1) / 2;
  //  for (int i = 1; i < n; i <<= 1) {
  //    ret = (ret + y.mod_xk(i << 1) * ret.inverse(i << 1)) * inv2;
  //  }
  //  return ret.mod_xk(n) * s;
  //}
  poly root(int n, int k = 2) const { //kth root of p(x) mod x^n
    if(is_zero()) return *this;
    if (k == 1) return mod_xk(n);
    assert(a[0] == 1);
    poly q({1});
    for(int i = 1; i < n; i <<= 1){
      if(k == 2) q += mod_xk(2 * i) * q.inverse(2 * i);
      else q = q * mint(k - 1) + mod_xk(2 * i) * q.inverse(2 * i).pow(k - 1, 2 * i);
      q = q.mod_xk(2 * i) / mint(k);
    }
    return q.mod_xk(n);
  }
  poly mulx(mint x) { //component-wise multiplication with x^k
    mint cur = 1; poly ans(*this);
    for(int i = 0; i < size(); i++) ans.a[i] *= cur, cur *= x;
    return ans;
  }
  poly mulx_sq(mint x) { //component-wise multiplication with x^{k^2}
    mint cur = x, total = 1, xx = x * x; poly ans(*this);
    for(int i = 0; i < size(); i++) ans.a[i] *= total, total *= cur, cur *= xx;
    return ans;
  }
  vector<mint> chirpz_even(mint z, int n) { //P(1), P(z^2), P(z^4), ..., P(z^2(n-1))
    int m = size() - 1;
    if(is_zero()) return vector<mint>(n, 0);
    vector<mint> vv(m + n);
    mint iz = z.inv(), zz = iz * iz, cur = iz, total = 1;
    for(int i = 0; i <= max(n - 1, m); i++) {
      if(i <= m) vv[m - i] = total;
      if(i < n) vv[m + i] = total;
      total *= cur; cur *= zz;
    }
    poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
    vector<mint> ans(n);
    for(int i = 0; i < n; i++) ans[i] = w[i];
    return ans;
  }
  //O(nlogn)
  vector<mint> chirpz(mint z, int n) { //P(1), P(z), P(z^2), ..., P(z^(n-1))
    auto even = chirpz_even(z, (n + 1) / 2);
    auto odd = mulx(z).chirpz_even(z, n / 2);
    vector<mint> ans(n);
    for(int i = 0; i < n / 2; i++) {
      ans[2 * i] = even[i];
      ans[2 * i + 1] = odd[i];
    }
    if(n % 2 == 1) ans[n - 1] = even.back();
    return ans;
  }
  poly shift_it(int m, vector<poly> &pw) {
    if (size() <= 1) return *this;
    while (m >= size()) m /= 2;
    poly q(a.begin() + m, a.end());
    return q.shift_it(m, pw) * pw[m] + mod_xk(m).shift_it(m, pw);
  };
  //n log(n)
  poly shift(mint a) { //p(x + a)
    int n = size();
    if (n == 1) return *this;
    vector<poly> pw(n);
    pw[0] = poly({1});
    pw[1] = poly({a, 1});
    int i = 2;
    for (; i < n; i *= 2) pw[i] = pw[i / 2] * pw[i / 2];
    return shift_it(i, pw);
  }
  mint eval(mint x) { // evaluates in single point x
    mint ans(0);
    for(int i = size() - 1; i >= 0; i--) {
      ans *= x;
      ans += a[i];
    }
    return ans;
  }
  // p(g(x))
  // O(n^2 logn)
  poly composition_brute(poly g, int deg){
    int n = size();
    poly c(deg, 0), pw({1});
    for (int i = 0; i < min(deg, n); i++){
      int d = min(deg, (int)pw.size());
      for (int j = 0; j < d; j++){
        c.a[j] += coef(i) * pw[j];
      }
      pw *= g;
      if (pw.size() > deg) pw.a.resize(deg);
    }
    return c;
  }
  // p(g(x))
  // O(nlogn * sqrt(nlogn))
  poly composition(poly g, int deg) {
    int n = size();
    int k = 1;
    while (k * k <= n) k++;
    k--;
    int d = n / k;
    if (k * d < n) d++;
    vector<poly> pw(k + 3, poly({1}));
    for(int i = 1; i <= k + 2; i++) {
      pw[i] = pw[i - 1] * g;
      if (pw[i].size() > deg) pw[i].a.resize(deg);
    }
    vector<poly> fi(k, poly(deg, 0));
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < d; j++) {
        int idx = i * d + j;
        if (idx >= n) break;
        int sz = min(fi[i].size(), pw[j].size());
        for (int t = 0; t < sz; t++) {
          fi[i].a[t] += pw[j][t] * coef(idx);
        }
      }
    }
    poly ret(deg, 0), gd({1});
    for (int i = 0; i < k; i++){
      fi[i] = fi[i] * gd;
      int sz = min((int)ret.size(), (int)fi[i].size());
      for (int j = 0; j < sz; j++) ret.a[j] += fi[i][j];
      gd = gd * pw[d];
      if (gd.size() > deg) gd.a.resize(deg);
    }
    return ret;
  }
  poly build(vector<poly> &ans, int v, int l, int r, vector<mint> &vec) { //builds evaluation tree for (x-a1)(x-a2)...(x-an)
    if(l == r) return ans[v] = poly({-vec[l], 1});
    int mid = l + r >> 1;
    return ans[v] = build(ans, 2 * v, l, mid, vec) * build(ans, 2 * v + 1, mid + 1, r, vec);
  }
  vector<mint> eval(vector<poly> &tree, int v, int l, int r, vector<mint> &vec) { // auxiliary evaluation function
    if(l == r) return {eval(vec[l])};
    if (size() < 400) {
      vector<mint> ans(r - l + 1, 0);
      for (int i = l; i <= r; i++) ans[i - l] = eval(vec[i]);
      return ans;
    }
    int mid = l + r >> 1;
    auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, mid, vec);
    auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, mid + 1, r, vec);
    A.insert(A.end(), B.begin(), B.end());
    return A;
  }
  //O(nlog^2n)
  vector<mint> eval(vector<mint> x) {// evaluate polynomial in (x_0, ..., x_n-1)
    int n = x.size();
    if(is_zero()) return vector<mint>(n, mint(0));
    vector<poly> tree(4 * n);
    build(tree, 1, 0, n - 1, x);
    return eval(tree, 1, 0, n - 1, x);
  }
  poly interpolate(vector<poly> &tree, int v, int l, int r, int ly, int ry, vector<mint> &y) { //auxiliary interpolation function
    if(l == r) return {y[ly] / a[0]};
    int mid = l + r >> 1;
    int midy = ly + ry >> 1;
    auto A = (*this % tree[2 * v]).interpolate(tree, 2 * v, l, mid, ly, midy, y);
    auto B = (*this % tree[2 * v + 1]).interpolate(tree, 2 * v + 1, mid + 1, r, midy + 1, ry, y);
    return A * tree[2 * v + 1] + B * tree[2 * v];
  }
};


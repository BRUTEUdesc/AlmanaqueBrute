template <typename T>
struct fraction {
    T p, q;
};
using F = fraction<ll>;

const ll inf = LLONG_MAX;

vector<ll> continued_fraction(F f) {
    vector<ll> a;
    while (f.q) {
        a.emplace_back(f.p / f.q);
        tie(f.p, f.q) = make_pair(f.q, f.p % f.q);
    }
    return a;
}

#warning "'convergents(a)' assumes 'a.back() != inf'"
// CAREFUL: assumes A.BACK()
pair<vector<ll>, vector<ll>> convergents(vector<ll> a) {
    vector<ll> p = {0, 1};
    vector<ll> q = {1, 0};

    int n = a.size();
    for (int i = 0; i < n; i++) {
        p.emplace_back(p.end()[-1] * a[i] + p.end()[-2]);
        q.emplace_back(q.end()[-1] * a[i] + q.end()[-2]);
    }

    return make_pair(p, q);
}

vector<ll> lca_continued(vector<ll> a, vector<ll> b) {
    int n_f = a.size();
    int n_g = b.size();

    vector<ll> ans;
    for (int i = 0; i < min(n_f, n_g); i++) {
        ans.emplace_back(min(a[i], b[i]));
        if (a[i] != b[i]) break;
    }
    ans.back()++;

    return ans;
}

F lca(F f, F g) {
    vector<ll> cont_f = continued_fraction(f);
    vector<ll> cont_g = continued_fraction(g);

    vector<ll> cont = lca_continued(cont_f, cont_g);

    auto [P, Q] = convergents(cont);
    return F(P.back(), Q.back());
}

// assumes a != b and a.back() = b.back() == inf
bool less_cont(vector<ll> a, vector<ll> b) {
    for (int i = 1; i < a.size(); i += 2) a[i] *= -1;
    for (int i = 1; i < b.size(); i += 2) b[i] *= -1;
    return a < b;
}

vector<ll> expand_continued_fraction(vector<ll> a) {
    // empty a = inf
    if (a.size()) {
        a.back()--;
        a.emplace_back(1);
        return a;
    } else return a;
}

// returns {a-eps, a+eps}
pair<vector<ll>, vector<ll>> plus_minus_eps(vector<ll> a) {
    vector<ll> b = expand_continued_fraction(a);
    a.emplace_back(inf);
    b.emplace_back(inf);
    return less_cont(a, b) ? make_pair(a, b) : make_pair(b, a);
}

// Mantem o MAXIMO das retas. As retas devem ser inseridas com coeficiente
// angular 'a' nao-decrescente. Para o minimo, inserir (-a, -b) e negar a resposta.
const ll INF = 1e18 + 18;
struct line {
    ll a, b;
    ll get(ll x) { return a * x + b; }
    ll intersect(line l) { // ceil((l.b - b) / (a - l.a))
        ll p = l.b - b, q = a - l.a;
        if (q < 0) p = -p, q = -q;
        return p >= 0 ? (p + q - 1) / q : -(-p / q);
    }
};
deque<pair<line, ll>> fila; // {reta, primeiro x em que ela eh a melhor}
void add_line(ll a, ll b) {
    line nova = {a, b};
    if (!fila.empty() && fila.back().first.a == a) {
        if (fila.back().first.b >= b) return;
        fila.pop_back();
    }
    while (!fila.empty() && fila.back().second >= nova.intersect(fila.back().first))
        fila.pop_back();
    ll x = fila.empty() ? -INF : nova.intersect(fila.back().first);
    fila.emplace_back(nova, x);
}
ll get_binary_search(ll x) {
    int esq = 0, dir = (int)fila.size() - 1, r = -1;
    while (esq <= dir) {
        int mid = (esq + dir) / 2;
        if (x >= fila[mid].second) {
            esq = mid + 1;
            r = mid;
        } else {
            dir = mid - 1;
        }
    }
    return fila[r].first.get(x);
}
// O(1) amortizado, usar apenas quando os x das consultas sao crescentes!
ll get(ll x) {
    while (fila.size() >= 2 && x >= fila[1].second) fila.pop_front();
    return fila.front().first.get(x);
}

bool ccw(pt &p, pt &a, pt &b, bool include_collinear = 0) {
    pt p1 = a - p;
    pt p2 = b - p;
    return include_collinear ? (p2 ^ p1) <= 0 : (p2 ^ p1) < 0;
}

void sort_by_angle(vector<pt>& v) { // sorta o vetor por angulo em relacao ao pivo
    pt p0 = *min_element(begin(v), end(v)); 
    sort(begin(v), end(v), [&](pt &l, pt &r) { // sorta clockwise
        pt p1 = l - p0;
        pt p2 = r - p0;
        ll c1 = p1 ^ p2;
        return c1 < 0 || ((c1 == 0) && p0.dist2(l) < p0.dist2(r));
    });
}

vector<pt> convex_hull(vector<pt> v, bool include_collinear = 0) {
    int n = size(v);

    sort_by_angle(v);

    if (include_collinear) {
        for (int i = n - 2; i >= 0; i--) { // reverte o ultimo lado do poligono
            if (ccw(v[0], v[n - 1], v[i])) {
                reverse(begin(v) + i + 1, end(v));
                break;
            }
        }
    }

    vector<pt> ch{v[0], v[1]};
    for (int i = 2; i < n; i++) {
        while (ch.size() > 2 && (ccw(ch.end()[-2], ch.end()[-1], v[i], !include_collinear))) ch.pop_back();
        ch.emplace_back(v[i]);
    }

    return ch;
}
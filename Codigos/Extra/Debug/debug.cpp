template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) { // opcional
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { // opcional
    os << "{";
    int n = (int)v.size();
    for (int i = 0; i < n; i++) {
        os << v[i];
        if (i < n - 1) os << ", ";
    }
    os << "}";
    return os;
}

void _print() { }
template <typename T, typename... U>
void _print(T a, U... b) {
    if (sizeof...(b)) {
        cerr << a << ", ";
        _print(b...);
    } else cerr << a;
}
#ifdef BRUTE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x), cerr << "]" << endl
#else
#define debug(...)
#endif
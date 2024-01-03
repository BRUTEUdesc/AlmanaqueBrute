pair<int, int> busca(string &t, int i, pair<int, int> &range) {
    int esq = range.first, dir = range.second, L = -1, R = -1;
    while (esq <= dir) {
        int mid = (esq + dir) / 2;
        if (s[sa[mid] + i] == t[i]) { L = mid; }
        if (s[sa[mid] + i] < t[i]) {
            esq = mid + 1;
        } else {
            dir = mid - 1;
        }
    }
    esq = range.first, dir = range.second;
    while (esq <= dir) {
        int mid = (esq + dir) / 2;
        if (s[sa[mid] + i] == t[i]) { R = mid; }
        if (s[sa[mid] + i] <= t[i]) {
            esq = mid + 1;
        } else {
            dir = mid - 1;
        }
    }
    return {L, R};
}
// count ocurences of s on t
int busca_string(string &t) {
    pair<int, int> range = {0, n - 1};
    for (int i = 0; i < t.size(); i++) {
        range = busca(t, i, range);
        if (range.first == -1) { return 0; }
    }
    return range.second - range.first + 1;
}
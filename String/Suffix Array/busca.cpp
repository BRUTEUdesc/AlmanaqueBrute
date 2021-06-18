pair<int, int> busca(char c, pair<int, int> &range, int delta) {
    int esq = range.first, dir = range.second, L = -1, R = -1;
    while (esq <= dir) {
        int mid = (esq + dir)/2;
        if (s[sa[mid]+delta] == c) L = mid;
        if (s[sa[mid]+delta] < c) esq = mid+1;
        else dir = mid-1; 
    }
    esq = range.first, dir = range.second;
    while (esq <= dir) {
        int mid = (esq + dir)/2;
        if (s[sa[mid]+delta] == c) R = mid;
        if (s[sa[mid]+delta] <= c) esq = mid+1;
        else dir = mid-1; 
    }
    return {L, R};
}

bool busca_string(string &s) {
    ii range = {0, sa.n-1};
    for (int i = 0; i < s.size(); i++) {
        range = busca(s[i], range, i);
        if (range.first == -1) return false;
    }
    return true;
}

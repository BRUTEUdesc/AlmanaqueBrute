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

const int MAX_N = 5e5+5;

struct suffix_array {
    string s;
    int n, sum, r, ra[MAX_N], sa[MAX_N], auxra[MAX_N], auxsa[MAX_N], c[MAX_N], lcp[MAX_N];
    void counting_sort(int k) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++) c[(i + k < n)? ra[i + k] : 0]++;
        for (int i = sum = 0; i < max(256, n); i++) sum += c[i], c[i] = sum - c[i];
        for (int i = 0; i < n; i++) auxsa[c[sa[i]+k < n? ra[sa[i]+k]:0]++] = sa[i];
        for (int i = 0; i < n; i++) sa[i] = auxsa[i];
    }
    void build_sa() {
        for (int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            auxra[sa[0]] = r = 0;
            for (int i = 1; i < n; i++) auxra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])? r:++r;
            for (int i = 0; i < n; i++) ra[i] = auxra[i];
            if (ra[sa[n-1]] == n-1) break;
        }
    }
    void build_lcp() {
        for (int i = 0, k = 0; i < n-1; i++) {
            int j = sa[ra[i]-1];
            while (s[i+k]==s[j+k]) k++;
            lcp[ra[i]] = k;
            if (k) k--;
        }
    }
    void set_string(string _s) {
        s = _s + '$';
        n = s.size();
        for (int i = 0; i < n; i++) ra[i] = s[i], sa[i] = i;
        build_sa();
        build_lcp();
        // for (int i = 0; i < n; i++) printf("%2d: %s\n", sa[i], s.c_str() + sa[i]);
    }
    int operator[](int i){return sa[i];}
    // search t's i-th char on range of s's suffixes
    pair<int, int> busca(string &t, int i, pair<int, int> &range) {
        int esq = range.first, dir = range.second, L = -1, R = -1;
        while (esq <= dir) {
            int mid = (esq + dir)/2;
            if (s[sa[mid]+i] == t[i]) L = mid;
            if (s[sa[mid]+i] < t[i]) esq = mid+1;
            else dir = mid-1; 
        }
        esq = range.first, dir = range.second;
        while (esq <= dir) {
            int mid = (esq + dir)/2;
            if (s[sa[mid]+i] == t[i]) R = mid;
            if (s[sa[mid]+i] <= t[i]) esq = mid+1;
            else dir = mid-1; 
        }
        return {L, R};
    }
    // count ocurences of s on t
    int busca_string(string &t) {
        pair<int, int> range = {0, n-1};
        for (int i = 0; i < t.size(); i++) {
            range = busca(t, i, range);
            if (range.first == -1) return 0;
        }
        return range.second - range.first + 1;
    }
} sa;

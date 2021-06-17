const int MAX_N = 1e5+5;

struct suffix_array {
    int n, sum, r, ra[MAX_N], sa[MAX_N], auxra[MAX_N], auxsa[MAX_N], c[MAX_N];
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
    suffix_array(string s) {
        s += '$';
        n = s.size();
        for (int i = 0; i < n; i++) ra[i] = s[i], sa[i] = i;
        build_sa();
        // for (int i = 0; i < n; i++) printf("%2d %2d: %s\n", i, sa[i], s.c_str() + sa[i]);
    }
};

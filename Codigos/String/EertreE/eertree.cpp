const int N = 6e6 + 15;
const int ALF = 10;

struct eertree {
    int str[N], len[N], lnk[N], cnt[N], first[N], node_cnt, it, last;
    ll palindrome_substring_sum;
    const char norm = '0';
    array<int, ALF> to[N];

    inline int get(char c) { return c - norm; }

    void set_string(const string &s) {
        int n = (int)s.size();
        memset(str, 0, sizeof(int) * (it + 1));
        memset(len, 0, sizeof(int) * (it + 1));
        memset(lnk, 0, sizeof(int) * (it + 1));
        memset(cnt, 0, sizeof(int) * (it + 1));
        for (int i = 0; i <= it; i++)
            for (int j = 0; j < ALF; j++) to[i][j] = 0;
        node_cnt = 2, it = 1, last = 0, str[0] = -1;
        len[0] = 0, len[1] = -1, lnk[0] = 1, lnk[1] = 1;
        for (int i = 0; i < n; i++) insert(s[i]);
        build_cnt();
    }

    void insert(char ch) {
        int c = get(ch);
        str[it] = c;
        while (str[it - 1 - len[last]] != c) last = lnk[last];
        if (!to[last][c]) {
            int prev = lnk[last];
            while (str[it - 1 - len[prev]] != c) prev = lnk[prev];
            lnk[node_cnt] = to[prev][c];
            len[node_cnt] = len[last] + 2;
            to[last][c] = node_cnt++;
        }
        last = to[last][c];
        first[last] = it;
        cnt[last]++;
        it++;
    }

    void build_cnt() {
        ll ans = 0;
        for (int i = it; i > 1; i--) {
            ans += cnt[i];
            cnt[lnk[i]] += cnt[i];
        }
        palindrome_substring_sum = ans;
    }

    inline ll number_of_palindromes() { return palindrome_substring_sum; }
    inline int number_of_distinct_palindromes() { return node_cnt - 2; }
} et;

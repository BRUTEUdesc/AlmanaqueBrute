// maxn = 2 * maximum N
const int MAXN = 3e5 + 5;
const int MAXS = 2 * MAXN + 5;
array<int, 26> to[MAXS];
int lnk[MAXS], len[MAXS];
int last = 1, id = 2;

void insert(int c) {
    int cur = id++;
    len[cur] = len[last] + 1;
    int p = last;
    while (p && !to[p][c]) {
        to[p][c] = cur;
        p = lnk[p];
    }
    if (p == 0) {
        lnk[cur] = 1;
    } else {
        int s = to[p][c];
        if (len[p] + 1 == len[s]) {
            lnk[cur] = s;
        } else {
            int clone = id++;
            len[clone] = len[p] + 1;
            lnk[clone] = lnk[s];
            to[clone] = to[s];
            while (to[p][c] == s) {
                to[p][c] = clone;
                p = lnk[p];
            }
            lnk[s] = lnk[cur] = clone;
        }
    }
    last = cur;
}

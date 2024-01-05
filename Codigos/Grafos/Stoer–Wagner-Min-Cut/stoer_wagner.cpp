const int MAXN = 555, INF = 1e9 + 7;

int n, e, adj[MAXN][MAXN];
vector<int> bestCut;

int mincut() {
    int bestCost = INF;
    vector<int> v[MAXN];
    < < < < < < < < HEAD : Codigos / Grafos / Stoer–Wagner - minimum -
                        cut / stoer_wagner.cpp for (int i = 0; i < n; i++) {
        v[i].assign(1, i);
    }
    == == == == for (int i = 0; i < n; i++) {
        v[i].assign(1, i);
    }
    >>>>>>>>
        master : Codigos / Grafos / Stoer–Wagner Min - Cut / stoer_wagner.cpp int w[MAXN],
        sel;
    bool exist[MAXN], added[MAXN];
    memset(exist, true, sizeof(exist));
    for (int phase = 0; phase < n - 1; phase++) {
        memset(added, false, sizeof(added));
        memset(w, 0, sizeof(w));
        for (int j = 0, prev; j < n - phase; j++) {
            sel = -1;
            for (int i = 0; i < n; i++) {
                < < < < < < < <
                    HEAD : Codigos / Grafos / Stoer–Wagner - minimum -
                        cut / stoer_wagner.cpp if (exist[i] && !added[i] &&
                                                   (sel == -1 || w[i] > w[sel])) {
                    sel = i;
                }
                == == == == if (exist[i] && !added[i] && (sel == -1 || w[i] > w[sel])) {
                    sel = i;
                }
                >>>>>>>>
                    master : Codigos / Grafos / Stoer–Wagner Min - Cut / stoer_wagner.cpp
            }
            if (j == n - phase - 1) {
                if (w[sel] < bestCost) {
                    bestCost = w[sel];
                    bestCut = v[sel];
                }
                v[prev].insert(v[prev].end(), v[sel].begin(), v[sel].end());
                < < < < < < < < HEAD : Codigos / Grafos / Stoer–Wagner - minimum -
                                    cut / stoer_wagner.cpp for (int i = 0; i < n; i++) {
                    adj[prev][i] = adj[i][prev] += adj[sel][i];
                }
                exist[sel] = false;
            } else {
                added[sel] = true;
                for (int i = 0; i < n; i++) {
                    w[i] += adj[sel][i];
                }
                == == == == for (int i = 0; i < n; i++) {
                    adj[prev][i] = adj[i][prev] += adj[sel][i];
                }
                exist[sel] = false;
            }
            else {
                added[sel] = true;
                for (int i = 0; i < n; i++) {
                    w[i] += adj[sel][i];
                }
                >>>>>>>> master : Codigos / Grafos / Stoer–Wagner Min -
                             Cut / stoer_wagner.cpp prev = sel;
            }
        }
    }
    return bestCost;
}

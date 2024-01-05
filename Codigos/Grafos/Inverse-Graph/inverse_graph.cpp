#include <bits/stdc++.h>
using namespace std;

set<int> nodes;
vector<set<int>> adj;

void bfs(int s) {
    queue<int> f;
    f.push(s);
    nodes.erase(s);
    set<int> aux;
    while (!f.empty()) {
        int x = f.front();
        f.pop();
        for (int y : nodes) {
            if (adj[x].count(y) == 0) {
                aux.insert(y);
            }
        }
        for (int y : aux) {
            f.push(y);
            nodes.erase(y);
        }
        aux.clear();
    }
}

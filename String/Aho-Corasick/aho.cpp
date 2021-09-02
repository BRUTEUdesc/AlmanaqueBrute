const int K = 26;

struct Vertex {
    int next[K], p = -1, link = -1, exi = -1, go[K];
    bool term = false;
    char pch;
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> aho(1);

void add_string(const string &s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (aho[v].next[c] == -1) {
            aho[v].next[c] = aho.size();
            aho.emplace_back(v, ch);
        }
        v = aho[v].next[c];
    }
    aho[v].term = true;
}

int go(int u, char ch);

int get_link(int u) {
    if (aho[u].link == -1) {
        if (u == 0 || aho[u].p == 0) aho[u].link = 0;
        else aho[u].link = go(get_link(aho[u].p), aho[u].pch);
    }
    return aho[u].link;
}

int go(int u, char ch) {
    int c = ch - 'a';
    if (aho[u].go[c] == -1) {
        if (aho[u].next[c] != -1) aho[u].go[c] = aho[u].next[c];
        else aho[u].go[c] = u == 0 ? 0 : go(get_link(u), ch);
    }
    return aho[u].go[c];
}

int exi(int u) {
    if (aho[u].exi != -1) return aho[u].exi;
    int v = get_link(u);
    return aho[u].exi = (v == 0 || aho[v].term? v : exi(v));
}
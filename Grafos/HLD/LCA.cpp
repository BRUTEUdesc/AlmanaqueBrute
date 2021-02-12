int lca(int a, int b) {
    if (pos[a] > pos[b]) swap(a, b);
    return (head[a] == head[b])? a:lca(a, pai[head[b]]);
}

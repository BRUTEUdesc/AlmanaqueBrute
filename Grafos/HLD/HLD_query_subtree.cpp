// usa HLD.cpp!!

int query_subtree(int u) {
    return seg_query(0, 0, n-1, pos[u], pos[u]+sz[u]-1);
}

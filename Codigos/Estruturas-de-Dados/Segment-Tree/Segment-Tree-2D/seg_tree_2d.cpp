const int MAX = 2505;

int n, m, mat[MAX][MAX], tree[4 * MAX][4 * MAX];

int lc(int x) { return 2 * x + 1; }
int rc(int x) { return 2 * x + 2; }

void build_y(int nx, int lx, int rx, int ny, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) tree[nx][ny] = mat[lx][ly];
        else tree[nx][ny] = tree[lc(nx)][ny] + tree[rc(nx)][ny];
    } else {
        int my = (ly + ry) / 2;
        build_y(nx, lx, rx, lc(ny), ly, my);
        build_y(nx, lx, rx, rc(ny), my + 1, ry);
        tree[nx][ny] = tree[nx][lc(ny)] + tree[nx][rc(ny)];
    }
}
void build_x(int nx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(lc(nx), lx, mx);
        build_x(rc(nx), mx + 1, rx);
    }
    build_y(nx, lx, rx, 0, 0, m - 1);
}
void build() { build_x(0, 0, n - 1); }

void update_y(int nx, int lx, int rx, int ny, int ly, int ry, int x, int y, int v) {
    if (ly == ry) {
        if (lx == rx) tree[nx][ny] = v;
        else tree[nx][ny] = tree[lc(nx)][ny] + tree[rc(nx)][ny];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my) update_y(nx, lx, rx, lc(ny), ly, my, x, y, v);
        else update_y(nx, lx, rx, rc(ny), my + 1, ry, x, y, v);
        tree[nx][ny] = tree[nx][lc(ny)] + tree[nx][rc(ny)];
    }
}
void update_x(int nx, int lx, int rx, int x, int y, int v) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx) update_x(lc(nx), lx, mx, x, y, v);
        else update_x(rc(nx), mx + 1, rx, x, y, v);
    }
    update_y(nx, lx, rx, 0, 0, m - 1, x, y, v);
}
void update(int x, int y, int v) { update_x(0, 0, n - 1, x, y, v); }

int sum_y(int nx, int ny, int ly, int ry, int qly, int qry) {
    if (ry < qly || ly > qry) return 0;
    if (qly <= ly && ry <= qry) return tree[nx][ny];
    int my = (ly + ry) / 2;
    return sum_y(nx, lc(ny), ly, my, qly, qry) + sum_y(nx, rc(ny), my + 1, ry, qly, qry);
}
int sum_x(int nx, int lx, int rx, int qlx, int qrx, int qly, int qry) {
    if (rx < qlx || lx > qrx) return 0;
    if (qlx <= lx && rx <= qrx) return sum_y(nx, 0, 0, m - 1, qly, qry);
    int mx = (lx + rx) / 2;
    return sum_x(lc(nx), lx, mx, qlx, qrx, qly, qry) +
           sum_x(rc(nx), mx + 1, rx, qlx, qrx, qly, qry);
}
int sum(int lx, int rx, int ly, int ry) { return sum_x(0, 0, n - 1, lx, rx, ly, ry); }

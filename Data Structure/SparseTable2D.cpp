// vector<vector<ll>> vec; SparseTable2D<ll> st(vec); で2D Sparse Tableをつくる。
// st.query(lx,rx,ly,ry); で[lx,rx),[ly,ry)のmaxなどを求める。
template <typename T>
struct SparseTable2D {
    vector<vector<vector<vector<T>>>> table;
    vector<int> LOG;
    T const e = -inf;
    T comp(T a, T b) {
        return max(a, b);
    };
    SparseTable2D(vector<vector<T>> &v) {
        int h = v.size();
        int w = v[0].size();
        LOG = vector<int>(max(h, w) + 1);
        rep(i, 2, max(h, w) + 1) LOG[i] = LOG[i / 2] + 1;
        table = vector<vector<vector<vector<T>>>>(LOG[h] + 1, vector<vector<vector<T>>>(LOG[w] + 1, vector<vector<T>>(h, vector<T>(w, e))));
        rep(i, 0, h) rep(j, 0, w) table[0][0][i][j] = v[i][j];
        rep(i, 0, LOG[h] + 1) rep(j, 0, LOG[w] + 1) rep(x, 0, h) rep(y, 0, w) {
            if(i < LOG[h]) table[i + 1][j][x][y] = comp(table[i][j][x][y], (x + (1 << i) < h) ? table[i][j][x + (1 << i)][y] : e);
            if(j < LOG[w]) table[i][j + 1][x][y] = comp(table[i][j][x][y], (y + (1 << j) < w) ? table[i][j][x][y + (1 << j)] : e);
        }
    }
    T query(int lx, int rx, int ly, int ry) {
        int kx = LOG[rx - lx];
        int ky = LOG[ry - ly];
        return comp(comp(table[kx][ky][lx][ly], table[kx][ky][rx - (1 << kx)][ly]), comp(table[kx][ky][lx][ry - (1 << ky)], table[kx][ky][rx - (1 << kx)][ry - (1 << ky)]));
    }
};

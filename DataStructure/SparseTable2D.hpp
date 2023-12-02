// vector<vector<ll>> vec; SparseTable2D<ll> st(vec); で2D Sparse Tableをつくる。
// st.query(lx,rx,ly,ry); で[lx,rx),[ly,ry)のmaxなどを求める。
#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct SparseTable2D {
    SparseTable2D(const vector<vector<T>>& v) {
        h = v.size();
        w = v[0].size();
        LOG = vector<int>(max(h, w) + 1);
        rep(i, 2, max(h, w) + 1) LOG[i] = LOG[i / 2] + 1;
        table = vector<vector<vector<vector<T>>>>(LOG[h] + 1, vector<vector<vector<T>>>(LOG[w] + 1, vector<vector<T>>(h, vector<T>(w, e()))));
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                table[0][0][i][j] = v[i][j];
            }
        }
        for(int i = 0; i <= LOG[h]; ++i) {
            for(int j = 0; j <= LOG[w]; ++j) {
                for(int x = 0; x < h; ++x) {
                    for(int y = 0; y < w; ++y) {
                        if(i < LOG[h]) table[i + 1][j][x][y] = op(table[i][j][x][y], (x + (1 << i) < h) ? table[i][j][x + (1 << i)][y] : e());
                        if(j < LOG[w]) table[i][j + 1][x][y] = op(table[i][j][x][y], (y + (1 << j) < w) ? table[i][j][x][y + (1 << j)] : e());
                    }
                }
            }
        }
    }
    T query(int lx, int rx, int ly, int ry) const {
        assert(0 <= lx and lx <= rx and rx <= h);
        assert(0 <= ly and ly <= ry and ry <= w);
        if(lx == rx or ly == ry) return e();
        int kx = LOG[rx - lx];
        int ky = LOG[ry - ly];
        return op(op(table[kx][ky][lx][ly], table[kx][ky][rx - (1 << kx)][ly]), op(table[kx][ky][lx][ry - (1 << ky)], table[kx][ky][rx - (1 << kx)][ry - (1 << ky)]));
    }

   private:
    inline static constexpr T INF = numeric_limits<T>::max() / 2;
    int h, w;
    vector<vector<vector<vector<T>>>> table;
    vector<int> LOG;
    inline T op(const T& a, const T& b) const {
        return min(a, b);
    };
    inline T e() const {
        return INF;
    }
};

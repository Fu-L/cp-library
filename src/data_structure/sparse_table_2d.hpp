#pragma once
#include "../template/template.hpp"
template <typename S, auto op, auto e>
struct SparseTable2D {
    SparseTable2D(const vector<vector<S>>& v)
        : h((int)v.size()), w((int)v[0].size()), LOG(max(h, w) + 1) {
        rep(i, 2, (int)LOG.size()) LOG[i] = LOG[i / 2] + 1;
        table = vector<vector<vector<vector<S>>>>(LOG[h] + 1, vector<vector<vector<S>>>(LOG[w] + 1, vector<vector<S>>(h, vector<S>(w, e()))));
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
    S query(int lx, int rx, int ly, int ry) const {
        assert(0 <= lx and lx <= rx and rx <= h);
        assert(0 <= ly and ly <= ry and ry <= w);
        if(lx == rx or ly == ry) return e();
        int kx = LOG[rx - lx];
        int ky = LOG[ry - ly];
        return op(op(table[kx][ky][lx][ly], table[kx][ky][rx - (1 << kx)][ly]), op(table[kx][ky][lx][ry - (1 << ky)], table[kx][ky][rx - (1 << kx)][ry - (1 << ky)]));
    }

   private:
    int h, w;
    vector<vector<vector<vector<S>>>> table;
    vector<int> LOG;
};
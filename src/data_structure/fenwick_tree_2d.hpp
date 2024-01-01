#pragma once
#include "src/template/template.hpp"
template <typename T>
struct FenwickTree2D {
    FenwickTree2D(int H, int W)
        : h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}
    void add(int i, int j, T z) {
        assert(0 <= i and i < h);
        assert(0 <= j and j < w);
        for(int x = i + 1; x <= h; x += x & -x) {
            for(int y = j + 1; y <= w; y += y & -y) {
                data[x - 1][y - 1] += z;
            }
        }
    }
    T sum(int li, int lj, int ri, int rj) {
        assert(0 <= li and li <= ri and ri <= h);
        assert(0 <= lj and lj <= rj and rj <= w);
        return sum(ri, rj) - sum(li, rj) - sum(ri, lj) + sum(li, lj);
    }
    T get(int i, int j) {
        assert(0 <= i and i < h);
        assert(0 <= j and j < w);
        return sum(i + 1, j + 1) - sum(i, j + 1) - sum(i + 1, j) + sum(i, j);
    }

   private:
    int h, w;
    vector<vector<T>> data;
    inline T sum(int i, int j) {
        T s = 0;
        for(int x = i; x > 0; x -= x & -x) {
            for(int y = j; y > 0; y -= y & -y) {
                s += data[x - 1][y - 1];
            }
        }
        return s;
    }
};
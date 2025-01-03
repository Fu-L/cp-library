#pragma once
#include "../template/template.hpp"
template <typename T>
struct FenwickTree2D {
    FenwickTree2D(const int H, const int W)
        : h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}
    void add(const int i, const int j, const T& z) {
        assert(0 <= i and i < h);
        assert(0 <= j and j < w);
        for(int x = i + 1; x <= h; x += x & -x) {
            for(int y = j + 1; y <= w; y += y & -y) {
                data[x - 1][y - 1] += z;
            }
        }
    }
    T sum(const int li, const int lj, const int ri, const int rj) const {
        assert(0 <= li and li <= ri and ri <= h);
        assert(0 <= lj and lj <= rj and rj <= w);
        return sum(ri, rj) - sum(li, rj) - sum(ri, lj) + sum(li, lj);
    }
    T get(const int i, const int j) const {
        assert(0 <= i and i < h);
        assert(0 <= j and j < w);
        return sum(i + 1, j + 1) - sum(i, j + 1) - sum(i + 1, j) + sum(i, j);
    }

   private:
    int h, w;
    vector<vector<T>> data;
    inline T sum(const int i, const int j) const {
        T s = 0;
        for(int x = i; x > 0; x -= x & -x) {
            for(int y = j; y > 0; y -= y & -y) {
                s += data[x - 1][y - 1];
            }
        }
        return s;
    }
};
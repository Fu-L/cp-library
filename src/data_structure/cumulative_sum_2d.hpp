#pragma once
#include "../template/template.hpp"
template <typename T>
struct CumulativeSum2D {
    CumulativeSum2D(const int H, const int W)
        : h(H), w(W), data(H + 1, vector<T>(W + 1, 0)) {}
    void add(const int i, const int j, const T& x) {
        assert(0 <= i and i < h);
        assert(0 <= j and j < w);
        data[i + 1][j + 1] += x;
    }
    void build() {
        for(int i = 1; i < (int)data.size(); ++i) {
            for(int j = 1; j < (int)data[i].size(); ++j) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }
    T sum(const int li, const int lj, const int ri, const int rj) const {
        assert(0 <= li and li <= ri and ri <= h);
        assert(0 <= lj and lj <= rj and rj <= w);
        return data[ri][rj] - data[li][rj] - data[ri][lj] + data[li][lj];
    }
    T get(const int i, const int j) const {
        assert(0 <= i and i < h);
        assert(0 <= j and j < w);
        return data[i + 1][j + 1] - data[i][j + 1] - data[i + 1][j] + data[i][j];
    }

   private:
    int h, w;
    vector<vector<T>> data;
};
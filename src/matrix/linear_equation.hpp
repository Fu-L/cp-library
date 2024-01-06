#pragma once
#include "../template/template.hpp"
#include "./matrix.hpp"
#include "./gauss_elimination.hpp"
template <typename T>
vector<vector<T>> linear_equation(Matrix<T> a, Matrix<T> b) {
    assert(a.H() == b.H() and b.W() == 1);
    int h = a.H(), w = a.W();
    Matrix<T> A(h, w + 1);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            A[i][j] = a[i][j];
        }
        A[i][w] = b[i][0];
    }
    auto p = gauss_elimination(A, w);
    int rank = p.first;
    for(int i = rank; i < h; ++i) {
        if(A[i][w] != 0) return vector<vector<T>>{};
    }
    vector<vector<T>> res(1, vector<T>(w));
    vector<int> pivot(w, -1);
    for(int i = 0, j = 0; i < rank; ++i) {
        while(A[i][j] == 0) ++j;
        res[0][j] = A[i][w], pivot[j] = i;
    }
    for(int j = 0; j < w; ++j) {
        if(pivot[j] == -1) {
            vector<T> x(w);
            x[j] = 1;
            for(int k = 0; k < j; ++k) {
                if(pivot[k] != -1) x[k] = -A[pivot[k]][j];
            }
            res.push_back(x);
        }
    }
    return res;
}
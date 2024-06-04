#pragma once
#include "../template/template.hpp"
#include "./matrix.hpp"
#include "./gauss_elimination.hpp"
template <typename T>
Matrix<T> inverse(const Matrix<T>& a) {
    const int n = a.H();
    assert(n > 0);
    assert(n == a.W());
    Matrix<T> m(n, 2 * n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            m[i][j] = a[i][j];
        }
        m[i][n + i] = 1;
    }
    auto [rank, det] = gauss_elimination(m, n);
    if(rank != n) {
        Matrix<T> res(0, 0);
        return res;
    }
    Matrix<T> b(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            b[i][j] = m[i][j + n];
        }
    }
    return b;
}
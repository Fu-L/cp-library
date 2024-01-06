#pragma once
#include "../template/template.hpp"
#include "./matrix.hpp"
template <typename T>
pair<int, T> gauss_elimination(Matrix<T>& a, int pivot_end = -1) {
    int h = a.H(), w = a.W(), rank = 0;
    assert(-1 <= pivot_end and pivot_end <= w);
    if(pivot_end == -1) pivot_end = w;
    T det = 1;
    for(int j = 0; j < pivot_end; ++j) {
        int idx = -1;
        for(int i = rank; i < h; ++i) {
            if(a[i][j] != T(0)) {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            det = 0;
            continue;
        }
        if(rank != idx) det = -det, swap(a[rank], a[idx]);
        det *= a[rank][j];
        if(a[rank][j] != T(1)) {
            T coeff = T(1) / a[rank][j];
            for(int k = j; k < w; ++k) a[rank][k] *= coeff;
        }
        for(int i = 0; i < h; ++i) {
            if(i == rank) continue;
            if(a[i][j] != T(0)) {
                T coeff = a[i][j] / a[rank][j];
                for(int k = j; k < w; ++k) a[i][k] -= a[rank][k] * coeff;
            }
        }
        ++rank;
    }
    return {rank, det};
}
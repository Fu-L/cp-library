#pragma once
#include "../template/template.hpp"
template <typename T>
void superset_zeta_transform(vector<T>& f, bool inv = true) {
    int n = (int)f.size();
    assert((n & (n - 1)) == 0);
    const int sign = inv ? 1 : -1;
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; ++j) {
            if((j & i) == 0) {
                f[j] += sign * f[j | i];
            }
        }
    }
}
template <typename T>
void subset_zeta_transform(vector<T>& f, bool inv = true) {
    int n = (int)f.size();
    assert((n & (n - 1)) == 0);
    const int sign = inv ? 1 : -1;
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; ++j) {
            if((j & i) == 0) {
                f[j | i] += f[j];
            }
        }
    }
}
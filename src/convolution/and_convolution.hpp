#pragma once
#include "../template/template.hpp"
#include "../math/zeta_transform.hpp"
template <typename T>
vector<T> and_convolution(vector<T> a, vector<T> b) {
    const int n = (int)a.size(), m = (int)b.size();
    assert(n == m and (n & (n - 1)) == 0);
    superset_zeta_transform(a);
    superset_zeta_transform(b);
    for(int i = 0; i < (int)a.size(); ++i) a[i] *= b[i];
    superset_zeta_transform(a, true);
    return a;
}
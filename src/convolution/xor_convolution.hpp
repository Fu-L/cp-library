#pragma once
#include "../template/template.hpp"
#include "../math/walsh_hadamard_transform.hpp"
template <typename T>
vector<T> xor_convolution(vector<T> a, vector<T> b) {
    const int n = (int)a.size(), m = (int)b.size();
    assert(n == m and (n & (n - 1)) == 0);
    walsh_hadamard_transform(a);
    walsh_hadamard_transform(b);
    for(int i = 0; i < (int)a.size(); i++) a[i] *= b[i];
    walsh_hadamard_transform(a, true);
    return a;
}
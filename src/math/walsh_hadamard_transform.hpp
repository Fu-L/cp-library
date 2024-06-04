#pragma once
#include "../template/template.hpp"
template <typename T>
void walsh_hadamard_transform(vector<T>& f, const bool inv = false) {
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    for(int i = 1; i < n; i <<= 1) {
        for(int j = 0; j < n; ++j) {
            if((j & i) == 0) {
                const T x = f[j], y = f[j | i];
                f[j] = x + y, f[j | i] = x - y;
            }
        }
    }
    if(inv) {
        if constexpr(is_integral<T>::value) {
            for(auto& x : f) x /= n;
        } else {
            const T invn = T(1) / T(f.size());
            for(auto& x : f) x *= invn;
        }
    }
}
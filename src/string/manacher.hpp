#pragma once
#include "../template/template.hpp"
template <typename T>
vector<int> manacher(const T& s) {
    const int n = (int)s.size();
    if(n == 0) return {};
    vector<int> odd(n), even(n), res(2 * n - 1);
    for(int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r ? 1 : min(odd[l + r - i], r - i + 1));
        while(0 <= i - k and i + k < n and s[i - k] == s[i + k]) ++k;
        odd[i] = k;
        if(i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    for(int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r ? 0 : min(even[l + r - i + 1], r - i + 1));
        while(0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k]) ++k;
        even[i] = k;
        if(i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        res[2 * i] = 2 * odd[i] - 1;
        if(i) res[2 * i - 1] = 2 * even[i];
    }
    return res;
}
#pragma once
#include "../template/template.hpp"
template <typename T>
vector<int> manacher(T s) {
    int n = (int)s.size();
    s.resize(2 * n - 1);
    for(int i = n - 1; i >= 0; --i) {
        s[2 * i] = s[i];
    }
    auto d = *min_element(s.begin(), s.end());
    for(int i = 0; i < n - 1; ++i) {
        s[2 * i + 1] = d;
    }
    n = (int)s.size();
    vector<int> res(n);
    for(int i = 0, j = 0; i < n;) {
        while(i - j >= 0 and i + j < n and s[i - j] == s[i + j]) ++j;
        res[i] = j;
        int k = 1;
        while(i - k >= 0 and i + k < n and k + res[i - k] < j) {
            res[i + k] = res[i - k];
            ++k;
        }
        i += k, j -= k;
    }
    for(int i = 0; i < n; ++i) {
        if(((i ^ res[i]) & 1) == 0) res[i]--;
    }
    return res;
}
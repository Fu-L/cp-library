#pragma once
#include "cp-library/src/template/template.hpp"
template <typename T>
vector<int> z_algorithm(const vector<T>& s) {
    int n = (int)s.size();
    if(n == 0) return {};
    vector<int> z(n);
    z[0] = 0;
    for(int i = 1, j = 0; i < n; ++i) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
        while(i + k < n and s[k] == s[i + k]) ++k;
        if(j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}
vector<int> z_algorithm(const string& s) {
    int n = (int)s.size();
    vector<int> s2(n);
    for(int i = 0; i < n; ++i) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}
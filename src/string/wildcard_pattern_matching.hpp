#pragma once
#include "../template/template.hpp"
#include "../convolution/convolution_ll.hpp"
vector<bool> wildcard_pattrn_matching(const string& t, const string& p) {
    int n = (int)t.size(), m = (int)p.size();
    if(n < m) return {};
    vector<long long> t1(n), t2(n), t3(n), p1(m), p2(m), p3(m);
    for(int i = 0; i < n; ++i) {
        if(t[i] == '*') continue;
        t1[i] = t[i] - 'a' + 1;
        t2[i] = t1[i] * t1[i];
        t3[i] = t2[i] * t1[i];
    }
    for(int i = 0; i < m; ++i) {
        if(p[i] == '*') continue;
        p1[m - 1 - i] = p[i] - 'a' + 1;
        p2[m - 1 - i] = p1[m - 1 - i] * p1[m - 1 - i];
        p3[m - 1 - i] = p2[m - 1 - i] * p1[m - 1 - i];
    }
    vector<long long> c31 = convolution_ll(t3, p1), c22 = convolution_ll(t2, p2), c13 = convolution_ll(t1, p3);
    vector<bool> res(n - m + 1);
    for(int i = 0; i < n - m + 1; ++i) {
        if(c31[i + m - 1] - 2 * c22[i + m - 1] + c13[i + m - 1] == 0) {
            res[i] = true;
        }
    }
    return res;
}
#pragma once
#include "../template/template.hpp"
template <class F>
vector<int> monotone_minima(const int n, const int m, const F& f) {
    vector<int> res(n);
    auto dfs = [&](const auto& dfs, const int is, const int ie, const int l, const int r) -> void {
        if(is == ie) return;
        const int i = (is + ie) / 2;
        int m = l;
        for(int k = l + 1; k < r; ++k) {
            if(!f(i, m, k)) m = k;
        }
        res[i] = m;
        dfs(dfs, is, i, l, m + 1);
        dfs(dfs, i + 1, ie, m, r);
    };
    dfs(dfs, 0, n, 0, m);
    return res;
}
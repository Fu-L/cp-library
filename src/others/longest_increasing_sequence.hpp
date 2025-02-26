#pragma once
#include "../template/template.hpp"
template <typename T>
vector<int> longest_increasing_sequence(const vector<T>& a) {
    const int n = a.size();
    vector<pair<T, int>> dp;
    vector<int> p(n, -1);
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(begin(dp), end(dp), make_pair(a[i], -i));
        if(it != begin(dp)) p[i] = -prev(it)->second;
        if(it == end(dp)) {
            dp.emplace_back(a[i], -i);
        } else {
            *it = make_pair(a[i], -i);
        }
    }
    vector<int> res;
    for(int i = -dp.back().second; i != -1; i = p[i]) res.push_back(i);
    reverse(begin(res), end(res));
    return res;
}
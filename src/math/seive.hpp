#pragma once
#include "../template/template.hpp"
pair<vector<int>, vector<int>> seive(int n) {
    assert(n >= 1);
    vector<int> min_factor(n + 1);
    iota(min_factor.begin(), min_factor.end(), 0);
    min_factor[0] = min_factor[1] = -1;
    vector<int> prime;
    for(int i = 2; i * i <= n; ++i) {
        if(min_factor[i] < i) continue;
        prime.push_back(i);
        for(int j = i * i; j <= n; j += i) {
            if(min_factor[j] == j) min_factor[j] = i;
        }
    }
    return {prime, min_factor};
}
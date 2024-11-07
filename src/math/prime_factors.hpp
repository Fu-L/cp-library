#pragma once
#include "../template/template.hpp"
vector<pair<long long, int>> prime_factors(long long n) {
    assert(n >= 1);
    vector<pair<long long, int>> res;
    for(long long i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            res.emplace_back(i, 0);
            while(n % i == 0) {
                n /= i;
                ++res.back().second;
            }
        }
    }
    if(n >= 2) res.emplace_back(n, 1);
    return res;
}
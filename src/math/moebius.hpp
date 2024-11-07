#pragma once
#include "../template/template.hpp"
#include "./prime_factors.hpp"
int moebius(const long long n) {
    assert(n >= 1);
    if(n == 1) return 1;
    vector<pair<long long, int>> p = prime_factors(n);
    int res = 1;
    for(const auto& it : p) {
        if(it.second >= 2) return 0;
        res = -res;
    }
    return res;
}
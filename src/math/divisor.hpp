#pragma once
#include "../template/template.hpp"
vector<long long> divisor(const long long n) {
    assert(n >= 1);
    vector<long long> res;
    for(long long i = 1; i <= n / i; ++i) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n / i) res.emplace_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
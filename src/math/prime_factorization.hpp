#pragma once
#include "../template/template.hpp"
map<long long, long long> prime_factor(long long n) {
    assert(n >= 1);
    map<long long, long long> res;
    for(long long i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) {
        res[n] = 1;
    }
    return res;
}
#pragma once
#include "../template/template.hpp"
constexpr long long pow_mod(long long x, long long n, const long long mod) {
    assert(n >= 0 and mod >= 1);
    x %= mod;
    if(x < 0) x += mod;
    long long res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
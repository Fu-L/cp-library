#pragma once
#include "../template/template.hpp"
constexpr ll pow_mod(ll x, ll n, ll mod) {
    assert(n >= 0 and mod >= 1);
    x %= mod;
    if(x < 0) x += mod;
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
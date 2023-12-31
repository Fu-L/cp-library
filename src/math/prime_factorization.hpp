#pragma once
#include "cp-library/src/template/template.hpp"
map<ll, ll> prime_factor(ll n) {
    assert(n >= 1);
    map<ll, ll> res;
    for(ll i = 2; i * i <= n; ++i) {
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
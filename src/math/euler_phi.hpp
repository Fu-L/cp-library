#pragma once
#include "../template/template.hpp"
ll euler_phi(ll n) {
    ll res = max(n, 0ll);
    for(ll i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            res -= res / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}
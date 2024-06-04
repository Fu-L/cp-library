#pragma once
#include "../template/template.hpp"
long long euler_phi(long long n) {
    long long res = max(n, 0ll);
    for(long long i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            res -= res / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}
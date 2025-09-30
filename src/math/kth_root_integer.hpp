#pragma once
#include "../template/template.hpp"
unsigned long long kth_root_integer(const unsigned long long x, const int k) {
    if(k <= 1) return k ? x : 1;
    if(x <= 1) return x;
    if(k >= 64) return 1;
    auto check = [&](unsigned long long a) -> bool {
        unsigned long long power = 1;
        for(int i = k; i;) {
            if(i & 1) {
                if(power > x / a) return false;
                power *= a;
            }
            if(i >>= 1) {
                if(a > x / a) return false;
                a *= a;
            }
        }
        return power <= x;
    };
    unsigned long long res = pow(x, 1.0 / k);
    while(!check(res)) --res;
    while(check(res + 1)) ++res;
    return res;
}
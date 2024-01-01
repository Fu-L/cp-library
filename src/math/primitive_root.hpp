#pragma once
#include "src/template/template.hpp"
#include "src/math/pow_mod.hpp"
constexpr int primitive_root(int m) {
    if(m == 2) return 1;
    if(m == 167772161) return 3;
    if(m == 469762049) return 3;
    if(m == 754974721) return 11;
    if(m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while(x % 2 == 0) x /= 2;
    for(int i = 3; (long long)(i)*i <= x; i += 2) {
        if(x % i == 0) {
            divs[cnt++] = i;
            while(x % i == 0) {
                x /= i;
            }
        }
    }
    if(x > 1) {
        divs[cnt++] = x;
    }
    for(int g = 2;; ++g) {
        bool ok = true;
        for(int i = 0; i < cnt; ++i) {
            if(pow_mod(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
}
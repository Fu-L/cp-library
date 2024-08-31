#pragma once
#include "../template/template.hpp"
template <template <typename> typename FPS, typename mint>
mint bostan_mori(const FPS<mint>& a, const FPS<mint>& c, long long k) {
    assert(k >= 0);
    if(k < (int)a.size()) return a[k];
    assert(a.size() >= c.size());
    FPS<mint> q = FPS<mint>{1} - (c << 1);
    FPS<mint> p = (a * q).pre((int)c.size());
    if(p.empty()) return 0;
    while(k > 0) {
        auto q2 = q;
        for(int i = 1; i < (int)q2.size(); i += 2) q2[i] = -q2[i];
        const auto s = p * q2;
        const auto t = q * q2;
        if(k & 1) {
            for(int i = 1; i < (int)s.size(); i += 2) p[i >> 1] = s[i];
            for(int i = 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];
        } else {
            for(int i = 0; i < (int)s.size(); i += 2) p[i >> 1] = s[i];
            for(int i = 0; i < (int)t.size(); i += 2) q[i >> 1] = t[i];
        }
        k >>= 1;
    }
    return p[0];
}
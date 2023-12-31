#pragma once
#include "cp-library/src/template/template.hpp"
template <template <typename> typename FormalPowerSeries, typename mint>
mint bostan_mori(const FormalPowerSeries<mint>& a, const FormalPowerSeries<mint>& c, ll k) {
    if(k < (int)a.size()) return a[k];
    assert(a.size() >= c.size());
    FormalPowerSeries<mint> q = FormalPowerSeries<mint>{1} - (c << 1);
    FormalPowerSeries<mint> p = (a * q).pre((int)c.size());
    while(k > 0) {
        auto q2 = q;
        for(int i = 1; i < (int)q2.size(); i += 2) q2[i] = -q2[i];
        auto s = p * q2;
        auto t = q * q2;
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
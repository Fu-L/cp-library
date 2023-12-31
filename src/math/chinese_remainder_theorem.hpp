#pragma once
#include "cp-library/src/template/template.hpp"
#include "cp-library/src/math/inv_gcd.hpp"
pair<ll, ll> chinese_remainder_theorem(const vector<ll>& r, const vector<ll>& m) {
    assert(r.size() == m.size());
    int n = (int)r.size();
    ll r0 = 0, m0 = 1;
    for(int i = 0; i < n; ++i) {
        assert(m[i] >= 1);
        ll r1 = r[i] % m[i], m1 = m[i];
        if(r1 < 0) r1 += m[i];
        if(m0 < m1) {
            swap(r0, r1);
            swap(m0, m1);
        }
        if(m0 % m1 == 0) {
            if(r0 % m1 != r1) return {0, 0};
            continue;
        }
        auto [g, im] = inv_gcd(m0, m1);
        ll u1 = m1 / g;
        if((r1 - r0) % g) return {0, 0};
        ll x = (r1 - r0) / g % u1 * im % u1;
        r0 += x * m0;
        m0 *= u1;
        if(r0 < 0) r0 += m0;
    }
    return {r0, m0};
}
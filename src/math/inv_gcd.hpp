#pragma once
#include "../template/template.hpp"
constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
    a %= b;
    if(a < 0) a += b;
    if(a == 0) return {b, 0};
    ll s = b, t = a, m0 = 0, m1 = 1;
    while(t) {
        const ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        ll tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if(m0 < 0) m0 += b / s;
    return {s, m0};
}
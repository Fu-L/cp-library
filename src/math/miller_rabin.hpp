#pragma once
#include "../template/template.hpp"
constexpr __int128_t pow_mod_128(__int128_t x, __int128_t n, __int128_t mod) {
    assert(n >= 0 and mod >= 1);
    x %= mod;
    if(x < 0) x += mod;
    __int128_t res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
constexpr bool miller_rabin(ll n) {
    if(n <= 2) return n == 2;
    if(n % 2 == 0) return false;
    constexpr ll bases[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll d = n - 1;
    while(d % 2 == 0) d /= 2;
    ll e = 1, rev = n - 1;
    for(const ll& base : bases) {
        if(base % n == 0) continue;
        ll t = d;
        ll y = pow_mod_128(base, t, n);
        while(t != n - 1 and y != e and y != rev) {
            y = (__int128_t)y * y % n;
            t *= 2;
        }
        if(y != rev and t % 2 == 0) return false;
    }
    return true;
}
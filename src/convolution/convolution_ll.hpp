#pragma once
#include "../template/template.hpp"
#include "../template/static_modint.hpp"
#include "./convolution.hpp"
vector<long long> convolution_ll(const vector<long long>& a, const vector<long long>& b) {
    const int n = (int)a.size(), m = (int)b.size();
    if(!n or !m) return {};
    static constexpr unsigned long long MOD1 = 754974721;
    static constexpr unsigned long long MOD2 = 167772161;
    static constexpr unsigned long long MOD3 = 469762049;
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;
    static constexpr unsigned long long i1 = 190329765;
    static constexpr unsigned long long i2 = 58587104;
    static constexpr unsigned long long i3 = 187290749;
    static constexpr int MAX_AB_BIT = 24;
    assert(n + m - 1 <= (1 << MAX_AB_BIT));
    using mint1 = StaticModint<MOD1>;
    using mint2 = StaticModint<MOD2>;
    using mint3 = StaticModint<MOD3>;
    vector<mint1> a1(n), b1(m);
    vector<mint2> a2(n), b2(m);
    vector<mint3> a3(n), b3(m);
    for(int i = 0; i < n; ++i) a1[i] = a[i];
    for(int i = 0; i < n; ++i) a2[i] = a[i];
    for(int i = 0; i < n; ++i) a3[i] = a[i];
    for(int i = 0; i < m; ++i) b1[i] = b[i];
    for(int i = 0; i < m; ++i) b2[i] = b[i];
    for(int i = 0; i < m; ++i) b3[i] = b[i];
    vector<mint1> c1 = convolution<mint1>(a1, b1);
    vector<mint2> c2 = convolution<mint2>(a2, b2);
    vector<mint3> c3 = convolution<mint3>(a3, b3);
    vector<long long> c(n + m - 1);
    for(int i = 0; i < n + m - 1; ++i) {
        unsigned long long x = 0;
        x += (c1[i].val() * i1) % MOD1 * M2M3;
        x += (c2[i].val() * i2) % MOD2 * M1M3;
        x += (c3[i].val() * i3) % MOD3 * M1M2;
        long long diff = c1[i].val() - ((long long)x % (long long)MOD1 + (long long)MOD1) % (long long)MOD1;
        if(diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }
    return c;
}
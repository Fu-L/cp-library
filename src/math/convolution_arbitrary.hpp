#pragma once
#include "../template/template.hpp"
#include "../template/static_modint.hpp"
#include "./convolution.hpp"
template <typename mint>
vector<mint> convolution_arbitary(const vector<mint>& a, const vector<mint>& b) {
    int n = (int)a.size(), m = (int)b.size();
    static constexpr ll MOD1 = 754974721;
    static constexpr ll MOD2 = 167772161;
    static constexpr ll MOD3 = 469762049;
    static constexpr ll M1_inv_M2 = 95869806;
    static constexpr ll M12_inv_M3 = 187290749;
    static constexpr ll M12_mod = MOD1 * MOD2 % mint::mod();
    using mint1 = StaticModint<(uint32_t)MOD1>;
    using mint2 = StaticModint<(uint32_t)MOD2>;
    using mint3 = StaticModint<(uint32_t)MOD3>;
    vector<mint1> a1(n), b1(m);
    vector<mint2> a2(n), b2(m);
    vector<mint3> a3(n), b3(m);
    for(int i = 0; i < n; ++i) a1[i] = a[i].val();
    for(int i = 0; i < n; ++i) a2[i] = a[i].val();
    for(int i = 0; i < n; ++i) a3[i] = a[i].val();
    for(int i = 0; i < m; ++i) b1[i] = b[i].val();
    for(int i = 0; i < m; ++i) b2[i] = b[i].val();
    for(int i = 0; i < m; ++i) b3[i] = b[i].val();
    vector<mint1> x = convolution<mint1>(a1, b1);
    vector<mint2> y = convolution<mint2>(a2, b2);
    vector<mint3> z = convolution<mint3>(a3, b3);
    vector<mint> c(n + m - 1);
    for(int i = 0; i < n + m - 1; ++i) {
        ll v1 = ((ll)y[i].val() - (ll)x[i].val()) * M1_inv_M2 % MOD2;
        if(v1 < 0) v1 += MOD2;
        ll v2 = ((ll)z[i].val() - ((ll)x[i].val() + MOD1 * v1) % MOD3) * M12_inv_M3 % MOD3;
        if(v2 < 0) v2 += MOD3;
        c[i] = (ll)x[i].val() + MOD1 * v1 + M12_mod * v2;
    }
    return c;
}
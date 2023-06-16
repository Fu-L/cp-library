template <class mint, internal::is_static_modint_t<mint> * = nullptr>
vector<mint> convolution_arbitary(const vector<mint> &a, const vector<mint> &b) {
    int n = int(a.size()), m = int(b.size());
    static constexpr ll MOD1 = 754974721;
    static constexpr ll MOD2 = 167772161;
    static constexpr ll MOD3 = 469762049;
    static constexpr ll M1_inv_M2 = internal::inv_gcd(MOD1, MOD2).second;
    static constexpr ll M12_inv_M3 = internal::inv_gcd(MOD1 * MOD2, MOD3).second;
    static constexpr ll M12_mod = (MOD1 * MOD2) % mint::mod();
    vector<ll> a_(n), b_(m);
    for(int i = 0; i < n; i++) a_[i] = a[i].val();
    for(int i = 0; i < m; i++) b_[i] = b[i].val();
    vector<ll> x = convolution<MOD1>(a_, b_);
    vector<ll> y = convolution<MOD2>(a_, b_);
    vector<ll> z = convolution<MOD3>(a_, b_);
    vector<mint> c(n + m - 1);
    for(int i = 0; i < n + m - 1; i++) {
        ll v1 = (y[i] - x[i]) * M1_inv_M2 % MOD2;
        if(v1 < 0) v1 += MOD2;
        ll v2 = (z[i] - (x[i] + MOD1 * v1) % MOD3) * M12_inv_M3 % MOD3;
        if(v2 < 0) v2 += MOD3;
        c[i] = x[i] + MOD1 * v1 + M12_mod * v2;
    }
    return c;
}
#pragma once
#include "../template/template.hpp"
template <typename mint>
struct Lucas {
    Lucas()
        : mod(mint::mod()), fact(mint::mod()), ifact(mint::mod()) {
        fact[0] = 1;
        for(int i = 1; i < mod; ++i) fact[i] = fact[i - 1] * i;
        ifact[mod - 1] = fact[mod - 1].inv();
        for(int i = mod - 1; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(long long n, long long k) {
        if(n < 0 or n < k or k < 0) return 0;
        mint res = 1;
        while(n > 0) {
            const long long n0 = n % mod, k0 = k % mod;
            if(n0 < k0) return 0;
            res *= fact[n0] * ifact[k0] * ifact[n0 - k0];
            n /= mod;
            k /= mod;
        }
        return res;
    }

   private:
    int mod;
    vector<mint> fact, ifact;
};
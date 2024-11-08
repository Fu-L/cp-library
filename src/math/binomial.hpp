#pragma once
#include "../template/template.hpp"
template <typename mint>
struct Binomial {
    Binomial(int n)
        : fac(n + 1), ifac(n + 1) {
        fac[0] = 1;
        for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
        ifac[n] = fac[n].inv();
        for(int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i;
    }
    mint fact(int n) const {
        if(n < 0) return 0;
        return fac[n];
    }
    mint perm(int n, int r) const {
        if(n < 0 or n < r or r < 0) return 0;
        return fac[n] * ifac[n - r];
    }
    mint comb(int n, int r) const {
        if(n < 0 or n < r or r < 0) return 0;
        return fac[n] * ifac[n - r] * ifac[r];
    }
    mint homo(int n, int r) const {
        if(n < 0 or r < 0) return 0;
        if(r == 0) return 1;
        return comb(n + r - 1, r);
    }
    mint operator()(int n, int r) const {
        return comb(n, r);
    }

   private:
    vector<mint> fac, ifac;
};
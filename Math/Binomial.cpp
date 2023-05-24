// mint ans=binom(n,k); でnCkを求める。
struct Binomial {
    vector<mint> fac, ifac;
    Binomial(int n)
        : fac(n + 1), ifac(n + 1) {
        fac[0] = 1;
        rep(i, 1, n + 1) fac[i] = fac[i - 1] * i;
        ifac[n] = fac[n].inv();
        rrep(i, n, 1) ifac[i - 1] = ifac[i] * i;
    }
    mint fact(int n) {
        if(n < 0) return 0;
        return fac[n];
    }
    mint perm(int n, int r) {
        if(n < 0 or n < r or r < 0) return 0;
        return fac[n] * ifac[n - r];
    }
    mint comb(int n, int r) {
        if(n < 0 or n < r or r < 0) return 0;
        return fac[n] * ifac[n - r] * ifac[r];
    }
    mint homo(int n, int r) {
        if(n < 0 or r < 0) return 0;
        if(r == 0) return 1;
        return comb(n + r - 1, r);
    }
    mint operator()(int n, int r) {
        return comb(n, r);
    }
} binom(1000005);

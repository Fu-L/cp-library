struct Lucas {
    int mod;
    vector<mint> fact, ifact;
    Lucas(int p) {
        mod = p;
        fact.resize(p);
        ifact.resize(p);
        fact[0] = 1;
        rep(i, 1, p) fact[i] = fact[i - 1] * i;
        ifact[p - 1] = fact[p - 1].inv();
        rrep(i, p - 1, 1) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if(k < 0 or k > n) return 0;
        mint res = 1;
        while(n > 0) {
            ll n0 = n % mod, k0 = k % mod;
            if(n0 < k0) return 0;
            res *= fact[n0] * ifact[k0] * ifact[n0 - k0];
            n /= mod;
            k /= mod;
        }
        return res;
    }
};

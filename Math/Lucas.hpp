#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
struct Lucas {
    Lucas(int p)
        : mod(p), fact(p), ifact(p) {
        fact[0] = 1;
        for(int i = 1; i < p; ++i) fact[i] = fact[i - 1] * i;
        ifact[p - 1] = fact[p - 1].inv();
        for(int i = p - 1; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(ll n, ll k) {
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

   private:
    int mod;
    vector<mint> fact, ifact;
};

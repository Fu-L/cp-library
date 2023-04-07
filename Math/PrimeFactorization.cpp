// map<ll,ll> mp=prime_factor(n); でnを素因数分解する。p.firstが素因数、p.secondが指数。
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> res;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            res[i]++;
            n = n / i;
        }
    }
    if(n != 1) {
        res[n] = 1;
    }
    return res;
}
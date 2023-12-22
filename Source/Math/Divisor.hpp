#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> divisor(ll n) {
    assert(n >= 1);
    vector<ll> res;
    for(ll i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);
        }
    }
    ranges::sort(res);
    return res;
}
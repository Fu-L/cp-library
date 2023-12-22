#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<vector<ll>, vector<bool>> seive(ll n) {
    assert(n >= 1);
    vector<bool> is_prime(n + 1, true);
    vector<ll> prime;
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= n; ++i) {
        if(is_prime[i]) {
            prime.push_back(i);
            for(ll j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return {prime, is_prime};
}
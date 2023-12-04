#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> prime;
vector<bool> is_prime;
void seive(ll n) {
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= n; ++i) {
        if(is_prime[i]) {
            prime.push_back(i);
            for(ll j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

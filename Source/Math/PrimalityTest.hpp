#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr bool is_prime(ll n) {
    assert(n >= 1);
    if(n == 1) return false;
    for(ll i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}
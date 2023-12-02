// bool flag=is_prime(n); でnが素数かどうかを判定する。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_prime(ll n) {
    if(n == 1) return false;
    for(ll i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

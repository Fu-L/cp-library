#pragma once
#include "src/template/template.hpp"
ll floor_sum(ll n, ll m, ll a, ll b) {
    ll res = 0;
    if(a >= m) res += (n - 1) * n * (a / m) / 2, a %= m;
    if(b >= m) res += n * (b / m), b %= m;
    ll y = (a * n + b) / m;
    if(y == 0) return res;
    ll x = y * m - b;
    res += (n - (x + a - 1) / a) * y;
    res += floor_sum(y, a, m, (a - x % a) % a);
    return res;
}
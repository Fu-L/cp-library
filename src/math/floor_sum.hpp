#pragma once
#include "../template/template.hpp"
constexpr long long floor_sum(const long long n, const long long m, long long a, long long b) {
    long long res = 0;
    if(a >= m) res += (n - 1) * n * (a / m) / 2, a %= m;
    if(b >= m) res += n * (b / m), b %= m;
    const long long y = (a * n + b) / m;
    if(y == 0) return res;
    const long long x = y * m - b;
    res += (n - (x + a - 1) / a) * y;
    res += floor_sum(y, a, m, (a - x % a) % a);
    return res;
}
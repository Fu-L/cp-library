#pragma once
#include "../template/template.hpp"
using Real = long double;
constexpr Real EPS = Real(1e-8), PI = 3.141592653589793238462643383279L;
int sign(const Real& r) {
    if(r <= -EPS) return -1;
    if(r >= +EPS) return +1;
    return 0;
}
bool eq(const Real& a, const Real& b) {
    return sign(a - b) == 0;
}
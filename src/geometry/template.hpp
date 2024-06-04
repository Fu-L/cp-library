#pragma once
#include "../template/template.hpp"
using Real = long double;
const Real EPS = Real(1e-8), PI = acos(Real(-1.0));
int sign(const Real& r) {
    if(r <= -EPS) return -1;
    if(r >= +EPS) return +1;
    return 0;
}
bool eq(const Real& a, const Real& b) {
    return sign(a - b) == 0;
}
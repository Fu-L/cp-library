#pragma once
#include "../template/template.hpp"
#include "../math/divisor_multiple_transform.hpp"
template <typename mint>
vector<mint> lcm_convolution(const vector<mint>& a, const vector<mint>& b) {
    assert(a.size() == b.size());
    auto s = a, t = b;
    DivisorTransform::zeta_transform(s);
    DivisorTransform::zeta_transform(t);
    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];
    DivisorTransform::moebius_transform(s);
    return s;
}
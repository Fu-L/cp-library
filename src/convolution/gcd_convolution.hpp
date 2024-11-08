#pragma once
#include "../template/template.hpp"
#include "../math/divisor_multiple_transform.hpp"
template <typename mint>
vector<mint> gcd_convolution(const vector<mint>& a, const vector<mint>& b) {
    assert(a.size() == b.size());
    auto s = a, t = b;
    MultipleTransform::zeta_transform(s);
    MultipleTransform::zeta_transform(t);
    for(int i = 0; i < (int)a.size(); ++i) s[i] *= t[i];
    MultipleTransform::moebius_transform(s);
    return s;
}
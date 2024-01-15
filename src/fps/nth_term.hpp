#pragma once
#include "../template/template.hpp"
#include "./berlekamp_massey.hpp"
#include "./bostan_mori.hpp"
template <template <typename> typename FPS, typename mint>
mint nth_term(const FPS<mint>& s, ll n) {
    assert(n >= 0);
    FPS<mint> c = berlekamp_massey(s);
    return bostan_mori(s, c, n);
}
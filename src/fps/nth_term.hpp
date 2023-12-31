#pragma once
#include "cp-library/src/template/template.hpp"
#include "cp-library/src/fps/berlekamp_massey.hpp"
#include "cp-library/src/fps/bostan_mori.hpp"
template <template <typename> typename FormalPowerSeries, typename mint>
mint nth_term(const FormalPowerSeries<mint>& s, ll n) {
    FormalPowerSeries<mint> c = berlekamp_massey(s);
    return bostan_mori(s, c, n);
}
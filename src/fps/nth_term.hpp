#pragma once
#include "../template/template.hpp"
#include "./berlekamp_massey.hpp"
#include "./bostan_mori.hpp"
template <template <typename> typename FormalPowerSeries, typename mint>
mint nth_term(const FormalPowerSeries<mint>& s, ll n) {
    FormalPowerSeries<mint> c = berlekamp_massey(s);
    return bostan_mori(s, c, n);
}
#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "src/template/template.hpp"
#include "src/template/static_modint.hpp"
#include "src/fps/formal_power_series.hpp"
#include "src/fps/bostan_mori.hpp"
using mint = modint998244353;
int main(void) {
    ll d, k;
    cin >> d >> k;
    FormalPowerSeries<mint> a(d), c(d);
    rep(i, 0, d) cin >> a[i];
    rep(i, 0, d) cin >> c[i];
    cout << bostan_mori(a, c, k) << '\n';
}
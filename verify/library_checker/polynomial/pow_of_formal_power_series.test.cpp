#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    ll m;
    cin >> n >> m;
    FormalPowerSeries<mint> f(n);
    rep(i, 0, n) cin >> f[i];
    FormalPowerSeries<mint> g = f.pow(m);
    rep(i, 0, n) cout << g[i] << " \n"[i + 1 == n];
}
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
using mint = modint998244353;
using fps = FormalPowerSeries<mint>;
int main(void) {
    int n;
    cin >> n;
    fps f(n);
    rep(i, 0, n) cin >> f[i];
    fps g = f.inv();
    rep(i, 0, n) cout << g[i] << " \n"[i + 1 == n];
}
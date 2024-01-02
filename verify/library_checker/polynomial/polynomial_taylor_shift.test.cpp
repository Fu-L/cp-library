#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    mint c;
    cin >> n >> c;
    FormalPowerSeries<mint> f(n);
    rep(i, 0, n) cin >> f[i];
    f = f.shift(c);
    rep(i, 0, n) cout << f[i] << " \n"[i + 1 == n];
}
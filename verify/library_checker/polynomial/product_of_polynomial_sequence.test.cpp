#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
#include "../../../src/fps/all_product.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    cin >> n;
    vector<int> d(n);
    int D = 0;
    vector<FormalPowerSeries<mint>> f(n);
    rep(i, 0, n) {
        cin >> d[i];
        D += d[i];
        f[i].resize(d[i] + 1, mint(0));
        rep(j, 0, d[i] + 1) cin >> f[i][j];
    }
    FormalPowerSeries<mint> ans = all_product(f);
    rep(i, 0, D + 1) cout << ans[i] << " \n"[i == D];
}
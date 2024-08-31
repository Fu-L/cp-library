#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
#include "../../../src/fps/berlekamp_massey.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    cin >> n;
    FormalPowerSeries<mint> a(n);
    rep(i, 0, n) cin >> a[i];
    FormalPowerSeries<mint> c = berlekamp_massey(a);
    int m = c.size();
    cout << m << '\n';
    rep(i, 0, m) {
        cout << c[i] << " \n"[i + 1 == m];
    }
}
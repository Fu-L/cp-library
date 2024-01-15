#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
using mint = modint998244353;
using fps = FormalPowerSeries<mint>;
int main(void) {
    int n, m;
    cin >> n >> m;
    fps f(n), g(m);
    rep(i, 0, n) cin >> f[i];
    rep(i, 0, m) cin >> g[i];
    fps q = f / g, r = f % g;
    cout << q.size() << ' ' << r.size() << '\n';
    rep(i, 0, (int)q.size()) {
        cout << q[i] << " \n"[i + 1 == (int)q.size()];
    }
    rep(i, 0, (int)r.size()) {
        cout << r[i] << " \n"[i + 1 == (int)r.size()];
    }
}
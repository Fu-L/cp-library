#define PROBLEM "https://yukicoder.me/problems/no/1559"
#include "../../src/template/template.hpp"
#include "../../src/template/static_modint.hpp"
#include "../../src/fps/formal_power_series_arbitrary.hpp"
#include "../../src/fps/nth_term.hpp"
using mint = modint1000000007;
using fps = FormalPowerSeriesArbitrary<mint>;
int main(void) {
    ll n, k;
    fps f(10);
    cin >> n >> f[0] >> f[1] >> k;
    rep(i, 2, 10) {
        f[i] = (f[i - 1] * f[i - 1] + k) / f[i - 2];
    }
    cout << nth_term(f, n - 1) << '\n';
}
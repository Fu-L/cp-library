#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/convolution/convolution_arbitrary.hpp"
using mint = modint1000000007;
int main(void) {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vector<mint> c = convolution_arbitrary(a, b);
    rep(i, 0, n + m - 1) cout << c[i] << " \n"[i + 1 == n + m - 1];
}
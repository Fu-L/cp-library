#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/convolution/convolution.hpp"
using mint = modint998244353;
int main(void) {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vector<mint> c = convolution(a, b);
    rep(i, 0, n + m - 1) cout << c[i] << " \n"[i + 1 == n + m - 1];
}
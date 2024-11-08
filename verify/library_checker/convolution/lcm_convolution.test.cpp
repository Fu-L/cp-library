#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/convolution/lcm_convolution.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    cin >> n;
    vector<mint> a(n + 1), b(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    vector<mint> c = lcm_convolution(a, b);
    rep(i, 1, n + 1) cout << c[i] << " \n"[i == n];
}
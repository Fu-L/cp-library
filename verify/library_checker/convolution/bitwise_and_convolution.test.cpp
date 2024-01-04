#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/convolution/and_convolution.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    cin >> n;
    vector<mint> a(1 << n), b(1 << n);
    rep(i, 0, 1 << n) cin >> a[i];
    rep(i, 0, 1 << n) cin >> b[i];
    vector<mint> c = and_convolution(a, b);
    rep(i, 0, 1 << n) cout << c[i] << " \n"[i + 1 == (1 << n)];
}
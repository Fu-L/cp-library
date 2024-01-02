#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "src/template/template.hpp"
#include "src/template/static_modint.hpp"
#include "src/math/matrix.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    ll k;
    cin >> n >> k;
    Matrix<mint> a(n, n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }
    Matrix<mint> b = a.pow(k);
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << b[i][j] << " \n"[j + 1 == n];
        }
    }
}
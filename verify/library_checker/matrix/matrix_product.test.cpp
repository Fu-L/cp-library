#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/matrix/matrix.hpp"
using mint = modint998244353;
int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    Matrix<mint> a(n, m), b(m, k);
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    rep(i, 0, m) {
        rep(j, 0, k) {
            cin >> b[i][j];
        }
    }
    Matrix<mint> c = a * b;
    rep(i, 0, n) {
        rep(j, 0, k) {
            cout << c[i][j] << " \n"[j + 1 == k];
        }
    }
}
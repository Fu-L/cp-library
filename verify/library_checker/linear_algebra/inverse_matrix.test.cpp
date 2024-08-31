#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/matrix/matrix.hpp"
#include "../../../src/matrix/inverse.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    cin >> n;
    Matrix<mint> a(n, n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }
    Matrix<mint> b = inverse(a);
    if(!b.H() and !b.W()) {
        cout << -1 << '\n';
        return 0;
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << b[i][j] << " \n"[j + 1 == n];
        }
    }
}
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "src/template/template.hpp"
#include "src/template/static_modint.hpp"
#include "src/math/matrix.hpp"
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
    cout << a.determinant() << '\n';
}
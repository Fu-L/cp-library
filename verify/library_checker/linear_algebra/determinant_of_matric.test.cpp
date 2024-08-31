#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/matrix/matrix.hpp"
#include "../../../src/matrix/gauss_elimination.hpp"
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
    auto [rank, det] = gauss_elimination(a);
    cout << det << '\n';
}
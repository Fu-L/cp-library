#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/matrix/gauss_elimination.hpp"
using mint = modint998244353;
int main(void) {
    int n, m;
    cin >> n >> m;
    Matrix<mint> a(n, m);
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    auto [rank, det] = gauss_elimination(a);
    cout << rank << '\n';
}
#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/matrix/matrix.hpp"
#include "../../../src/matrix/linear_equation.hpp"
using mint = modint998244353;
int main(void) {
    int n, m;
    cin >> n >> m;
    Matrix<mint> a(n, m), b(n, 1);
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    rep(i, 0, n) {
        cin >> b[i][0];
    }
    vector<vector<mint>> ans = linear_equation(a, b);
    if(ans == vector<vector<mint>>{}) {
        cout << -1 << '\n';
        return 0;
    }
    int r = ans.size();
    cout << r - 1 << '\n';
    rep(i, 0, r) {
        rep(j, 0, m) {
            cout << ans[i][j] << " \n"[j + 1 == m];
        }
    }
}
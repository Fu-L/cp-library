#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/matrix/matrix.hpp"
int main() {
    Matrix<int> a(2, 3), b(3, 4);
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    rep(i, 0, 3) rep(j, 0, 4) b[i][j] = i + j;
    a *= b;
    assert(a.H() == 2);
    assert(a.W() == 4);
    Matrix<int> c(4, 1, 1);
    Matrix<int> d = a * c;
    assert(d.H() == 2);
    assert(d.W() == 1);
    int x, y;
    cin >> x >> y;
    cout << x + y << '\n';
}
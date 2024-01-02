#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"
#include "../../../src/template/template.hpp"
#include "../../../src/math/extgcd.hpp"
int main(void) {
    ll a, b, x, y;
    cin >> a >> b;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << '\n';
}
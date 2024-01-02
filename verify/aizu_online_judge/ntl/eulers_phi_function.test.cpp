#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include "../../../src/template/template.hpp"
#include "../../../src/math/euler_phi.hpp"
int main(void) {
    ll n;
    cin >> n;
    cout << euler_phi(n) << '\n';
}
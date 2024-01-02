#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
#include "../../../src/template/template.hpp"
#include "../../../src/math/pow_mod.hpp"
int main(void) {
    ll m, n;
    cin >> m >> n;
    cout << pow_mod(m, n, 1000000007) << '\n';
}
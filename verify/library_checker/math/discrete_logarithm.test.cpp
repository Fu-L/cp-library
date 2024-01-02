#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../../../src/template/template.hpp"
#include "../../../src/math/log_mod.hpp"
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        ll x, y, m;
        cin >> x >> y >> m;
        cout << log_mod(x, y, m) << '\n';
    }
}
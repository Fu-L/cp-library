#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "src/template/template.hpp"
#include "src/math/floor_sum.hpp"
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << floor_sum(n, m, a, b) << '\n';
    }
}
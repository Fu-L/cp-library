#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "../../../src/template/template.hpp"
#include "../../../src/math/prime_factors.hpp"
int main(void) {
    ll n;
    cin >> n;
    vector<pair<ll, int>> p = prime_factors(n);
    cout << n << ':';
    for(const auto& it : p) {
        for(int i = 0; i < it.second; ++i) {
            cout << ' ' << it.first;
        }
    }
    cout << '\n';
}
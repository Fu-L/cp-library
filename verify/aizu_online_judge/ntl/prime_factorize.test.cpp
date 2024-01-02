#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "../../../src/template/template.hpp"
#include "../../../src/math/prime_factorization.hpp"
int main(void) {
    ll n;
    cin >> n;
    map<ll, ll> mp = prime_factor(n);
    cout << n << ':';
    for(auto it : mp) {
        for(int i = 0; i < it.second; ++i) {
            cout << ' ' << it.first;
        }
    }
    cout << '\n';
}
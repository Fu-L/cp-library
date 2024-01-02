#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "src/template/template.hpp"
#include "src/math/miller_rabin.hpp"
int main(void) {
    int q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        if(miller_rabin(n)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}
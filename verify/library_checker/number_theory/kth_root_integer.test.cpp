#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include "../../../src/template/template.hpp"
#include "../../../src/math/kth_root_integer.hpp"
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        unsigned long long a, k;
        cin >> a >> k;
        cout << kth_root_integer(a, k) << '\n';
    }
}
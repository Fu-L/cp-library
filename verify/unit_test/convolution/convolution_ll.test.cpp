#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/random_number_generator.hpp"
#include "../../../src/convolution/convolution_ll.hpp"
void test() {
    int n = rng(0, 1000), m = rng(0, 1000);
    vector<ll> a(n), b(m);
    rep(i, 0, n) a[i] = rng(-1000000, 1000000);
    rep(i, 0, m) b[i] = rng(-1000000, 1000000);
    vector<ll> c = convolution_ll(a, b);
    vector<ll> expected(n + m - 1);
    rep(i, 0, n + m - 1) {
        rep(j, 0, i + 1) {
            if(0 <= j and j < n and 0 <= i - j and i - j < m) expected[i] += a[j] * b[i - j];
        }
    }
    rep(i, 0, n + m - 1) {
        assert(c[i] == expected[i]);
    }
}
int main(void) {
    constexpr int test_num = 100;
    rep(_, 0, test_num) {
        test();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
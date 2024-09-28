#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/random_number_generator.hpp"
#include "../../../src/convolution/or_convolution.hpp"
void test() {
    int n = 1 << rng(0, 12);
    vector<ll> a(n), b(n);
    rep(i, 0, n) a[i] = rng(-1000000, 1000000);
    rep(i, 0, n) b[i] = rng(-1000000, 1000000);
    vector<ll> c = or_convolution(a, b);
    if(!n) {
        assert(c.empty());
        return;
    }
    vector<ll> expected(n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            expected[i | j] += a[i] * b[j];
        }
    }
    rep(i, 0, n) {
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
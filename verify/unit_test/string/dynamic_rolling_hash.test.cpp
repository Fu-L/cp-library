#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/random_number_generator.hpp"
#include "../../../src/template/modint_2_61m1.hpp"
#include "../../../src/string/dynamic_rolling_hash.hpp"
using mint = Modint_2_61m1;
void test() {
    int n = rng(1, 2000), q = 2000;
    string s = "";
    rep(i, 0, n) {
        s += 'a' + rng(0, 25);
    }
    ll base = rng(1ll << 10, 1ll << 60);
    DynamicRollingHash drh(s, base);
    while(q--) {
        int type = rng(0, 1);
        if(type == 0) {
            int len = rng(0, n);
            int l = rng(0, n - len), r = l + len;
            mint ans = 0, b = 1;
            rep(i, l, r) {
                ans += b * s[i];
                b *= base;
            }
            assert(drh.get(l, r) == ans.val());
        } else {
            int idx = rng(0, n - 1);
            char c = 'a' + rng(0, 25);
            s[idx] = c;
            drh.set(idx, c);
        }
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
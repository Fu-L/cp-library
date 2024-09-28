#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/random_number_generator.hpp"
#include "../../../src/template/dynamic_modint.hpp"
#include "../../../src/math/lucas.hpp"
#include "../../../src/math/miller_rabin.hpp"
using mint = modint;
void test() {
    static Lucas<mint> binom;
    int n = rng(1, 5000000), k = rng(0, k);
    mint ans = 1;
    rep(i, 1, k + 1) {
        ans *= (n - i) / i;
    }
    assert(binom(n, k).val() == ans.val());
}
int main(void) {
    int p = 1;
    while(!miller_rabin(p)) {
        p = rng(2, 1e8);
    }
    mint::set_mod(p);
    constexpr int test_num = 1000;
    rep(_, 0, test_num) {
        test();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
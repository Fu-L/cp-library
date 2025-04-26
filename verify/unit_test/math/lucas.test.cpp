#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/random_number_generator.hpp"
#include "../../../src/template/dynamic_modint.hpp"
#include "../../../src/math/lucas.hpp"
#include "../../../src/math/miller_rabin.hpp"
using mint = modint;
void test() {
    static Lucas<mint> binom;
    int n = rng(1, 200000), k = rng(0, n);
    mint ans = 1;
    int cnt = 0;
    rep(i, 1, k + 1) {
        int p = n - (i - 1), q = i;
        while(p % mint::mod() == 0) {
            cnt++;
            p /= mint::mod();
        }
        while(q % mint::mod() == 0) {
            cnt--;
            q /= mint::mod();
        }
        ans *= mint(p) / q;
    }
    if(cnt > 0) ans = 0;
    assert(binom(n, k).val() == ans.val());
}
int main(void) {
    int p = 1;
    while(!miller_rabin(p)) {
        p = rng(2, 200000);
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
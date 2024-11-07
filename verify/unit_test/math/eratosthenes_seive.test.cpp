#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/template/random_number_generator.hpp"
#include "../../../src/math/eratosthenes_seive.hpp.hpp"
#include "../../../src/math/is_prime.hpp"
#include "../../../src/math/euler_phi.hpp"
#include "../../../src/math/moebius.hpp"
void test() {
    EratosthenesSeive seive(10000000);
    rep(i, 0, 10000) {
        int n = rng(1, 10000000);
        if(is_prime(n)) {
            assert(seive.min_factor[n] == n);
        } else {
            assert(seive.min_factor[n] != n);
        }
        if(is_prime(i)) {
            assert(seive.min_factor[i] == i);
        } else {
            assert(seive.min_factor[i] != i);
        }
        assert(euler_phi(n) == seive.euler[n]);
        assert(moebius(n) == seive.moebius[n]);
    }
    rep(i, 1, 100) {
        if(is_prime(i)) {
            assert(seive.min_factor[i] == i);
        } else {
            assert(seive.min_factor[i] != i);
        }
        assert(euler_phi(i) == seive.euler[i]);
        assert(moebius(i) == seive.moebius[i]);
    }
}
int main(void) {
    test();
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
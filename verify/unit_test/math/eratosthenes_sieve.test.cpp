#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/random_number_generator.hpp"
#include "../../../src/math/eratosthenes_sieve.hpp"
#include "../../../src/math/is_prime.hpp"
#include "../../../src/math/euler_phi.hpp"
#include "../../../src/math/moebius.hpp"
#include "../../../src/math/divisor.hpp"
#include "../../../src/math/prime_factors.hpp"
void test() {
    EratosthenesSieve sieve(10000000);
    rep(i, 0, 10000) {
        int n = rng(1, 10000000);
        if(is_prime(n)) {
            assert(sieve.min_factor[n] == n);
        } else {
            assert(sieve.min_factor[n] != n);
        }
        if(is_prime(i)) {
            assert(sieve.min_factor[i] == i);
        } else {
            assert(sieve.min_factor[i] != i);
        }
        assert(euler_phi(n) == sieve.euler[n]);
        assert(moebius(n) == sieve.moebius[n]);
    }
    rep(i, 1, 100) {
        if(is_prime(i)) {
            assert(sieve.min_factor[i] == i);
        } else {
            assert(sieve.min_factor[i] != i);
        }
        assert(euler_phi(i) == sieve.euler[i]);
        assert(moebius(i) == sieve.moebius[i]);
    }
    rep(i, 1, 10000) {
        int n = rng(1, 10000000);
        vector<pair<int, int>> pf1 = sieve.prime_factors(n);
        vector<pair<long long, int>> pf2 = prime_factors(n);
        assert(pf1.size() == pf2.size());
        for(int i = 0; i < (int)pf1.size(); ++i) {
            assert(pf1[i].first == pf2[i].first);
            assert(pf1[i].second == pf2[i].second);
        }
        vector<int> d1 = sieve.divisor(n);
        vector<ll> d2 = divisor(n);
        assert(d1.size() == d2.size());
        for(int i = 0; i < (int)d1.size(); ++i) {
            assert(d1[i] == d2[i]);
        }
    }
}
int main(void) {
    test();
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
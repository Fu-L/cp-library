#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "src/template/template.hpp"
#include "src/template/dynamic_modint.hpp"
#include "src/math/binomial.hpp"
using mint = modint;
int main(void) {
    int t, m;
    cin >> t >> m;
    mint::set_mod(m);
    Binomial<mint> binom(min(m - 1, 10000005));
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << binom(n, k) << '\n';
    }
}
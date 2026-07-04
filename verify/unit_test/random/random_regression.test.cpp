#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/permuted_congruential_generator.hpp"
int main() {
    rep(_, 0, 1000) {
        int x = rng(numeric_limits<int>::min(), numeric_limits<int>::max());
        (void)x;
        unsigned int y = rng(0u, numeric_limits<unsigned int>::max());
        (void)y;
        int z = rng(-10, 10);
        assert(-10 <= z and z <= 10);
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
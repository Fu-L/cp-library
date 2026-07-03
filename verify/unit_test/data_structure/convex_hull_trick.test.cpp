#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/permuted_congruential_generator.hpp"
#include "../../../src/data_structure/convex_hull_trick.hpp"
void test_random() {
    const int n = rng(1, 200);
    vector<pair<ll, ll>> lines;
    ConvexHullTrick<ll> cht;
    ll a = rng(-1000, 1000);
    rep(i, 0, n) {
        a -= rng(0, 5);
        const ll b = rng(-1000000, 1000000);
        lines.emplace_back(a, b);
        cht.add(a, b);
    }
    ll x = rng(-1000, 1000);
    const int query_num = 200;
    rep(_, 0, query_num) {
        x += rng(0, 10);
        ll expected = inf;
        for(const auto& [a, b] : lines) {
            expected = min(expected, a * x + b);
        }
        assert(cht(x) == expected);
    }
}
void test_sample_like() {
    ConvexHullTrick<ll> cht;
    vector<pair<ll, ll>> lines{{5, 3}, {2, 10}, {-1, 20}, {-4, 100}};
    for(const auto& [a, b] : lines) cht.add(a, b);
    rep(x, -10, 31) {
        ll expected = inf;
        for(const auto& [a, b] : lines) {
            expected = min(expected, a * x + b);
        }
        assert(cht(x) == expected);
    }
}
int main(void) {
    test_sample_like();
    constexpr int test_num = 100;
    rep(_, 0, test_num) {
        test_random();
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}

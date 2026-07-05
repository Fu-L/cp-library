#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/random/permuted_congruential_generator.hpp"
#include "../../../src/data_structure/dynamic_li_chao_tree.hpp"
void test_empty_segment() {
    DynamicLiChaoTree<ll, -10, 10> cht;
    cht.add_segment(0, 0, -100, -100);
    rep(x, -10, 11) assert(cht(x) == numeric_limits<ll>::max());
}
void test_random_segments() {
    constexpr int low = -20, high = 20;
    DynamicLiChaoTree<ll, low, high> cht;
    vector<tuple<ll, ll, ll, ll>> segments;
    rep(_, 0, 200) {
        int l = rng(low, high);
        int r = rng(l, high + 1);
        int a = rng(-20, 20);
        int b = rng(-100, 100);
        cht.add_segment(l, r, a, b);
        segments.emplace_back(l, r, a, b);
        rep(x, low, high + 1) {
            ll expected = numeric_limits<ll>::max();
            for(const auto& [sl, sr, sa, sb] : segments) {
                if(sl <= x and x < sr) expected = min(expected, sa * x + sb);
            }
            assert(cht(x) == expected);
        }
    }
}
int main() {
    test_empty_segment();
    rep(_, 0, 50) test_random_segments();
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
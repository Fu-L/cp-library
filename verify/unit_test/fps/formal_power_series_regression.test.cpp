#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/modint/static_modint.hpp"
#include "../../../src/fps/formal_power_series.hpp"
#include "../../../src/fps/formal_power_series_arbitrary.hpp"
#include "../../../src/fps/formal_power_series_ll.hpp"
using mint = StaticModint<998244353>;
using mint2 = StaticModint<1000000007>;
template <typename FPS>
void test_common() {
    FPS f{1, 2, 3};
    f = vector<typename FPS::value_type>{4};
    assert(f.size() == 1);
    assert(f[0] == typename FPS::value_type(4));
    FPS g{1, 2, 3};
    FPS h = -g;
    assert(g[0] == typename FPS::value_type(1));
    assert(g[1] == typename FPS::value_type(2));
    assert(g[2] == typename FPS::value_type(3));
    assert(h[0] == typename FPS::value_type(-1));
    assert(h[1] == typename FPS::value_type(-2));
    assert(h[2] == typename FPS::value_type(-3));
    FPS p{1, 2, 3};
    p *= FPS{};
    assert(p.empty());
}
int main() {
    test_common<FormalPowerSeries<mint>>();
    test_common<FormalPowerSeriesArbitrary<mint2>>();
    test_common<FormalPowerSeriesLL<long long>>();
    FormalPowerSeries<mint> f{1, 2, 3};
    assert(f.log(0).empty());
    assert(FormalPowerSeries<mint>{}.shift(5).empty());
    FormalPowerSeriesArbitrary<mint2> g{1, 2, 3};
    assert(g.log(0).empty());
    assert(FormalPowerSeriesArbitrary<mint2>{}.shift(5).empty());
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
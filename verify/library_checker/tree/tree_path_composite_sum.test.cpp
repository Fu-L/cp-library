#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/rerooting.hpp"
#include "../../../src/template/static_modint.hpp"
using mint = modint998244353;
int main(void) {
    int n;
    cin >> n;
    vector<mint> a(n);
    rep(i, 0, n) cin >> a[i];
    Graph<int> g(n);
    map<pair<int, int>, pair<mint, mint>> mp;
    rep(i, 0, n - 1) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        g.add_edge(u, v);
        mp[minmax(u, v)] = {b, c};
    }
    using DP = pair<mint, int>;
    auto f1 = [&](const DP& x, const DP& y) -> DP {
        return {x.first + y.first, x.second + y.second};
    };
    auto f2 = [&](const DP& x, const int child, const int parent) -> DP {
        auto [b, c] = mp[minmax(child, parent)];
        return {(x.first + a[child]) * b + c * (x.second + 1), x.second + 1};
    };
    const DP id = {0, 0};
    vector<DP> dp = rerooting(g, f1, f2, id);
    rep(i, 0, n) {
        cout << dp[i].first + a[i] << " \n"[i + 1 == n];
    }
}
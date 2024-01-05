#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_B"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/rerooting.hpp"
int main(void) {
    int n;
    cin >> n;
    Graph<int> g(n);
    map<pair<int, int>, int> mp;
    rep(i, 0, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
        mp[{a, b}] = c;
        mp[{b, a}] = c;
    }
    using DP = int;
    auto f1 = [&](DP x, DP y) -> DP {
        return max(x, y);
    };
    auto f2 = [&](DP x, int child, int parent) -> DP {
        return x + mp[{child, parent}];
    };
    DP id = 0;
    vector<DP> dp = rerooting(g, f1, f2, id);
    rep(i, 0, n) {
        cout << dp[i] << '\n';
    }
}
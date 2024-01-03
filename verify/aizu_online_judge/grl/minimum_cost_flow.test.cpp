#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/min_cost_flow.hpp"
int main(void) {
    int n, m, f;
    cin >> n >> m >> f;
    MinCostFlow<int, int> g(n);
    rep(i, 0, m) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        g.add_edge(u, v, c, d);
    }
    pair<int, int> ans = g.flow(0, n - 1, f);
    if(ans.first == f) {
        cout << ans.second << '\n';
    } else {
        cout << -1 << '\n';
    }
}
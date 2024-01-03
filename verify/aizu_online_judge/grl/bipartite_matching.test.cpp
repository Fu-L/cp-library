#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/max_flow.hpp"
int main(void) {
    int n, m, e;
    cin >> n >> m >> e;
    MaxFlow<int> g(n + m + 2);
    rep(i, 0, e) {
        int x, y;
        cin >> x >> y;
        g.add_edge(x, n + y, 1);
    }
    rep(i, 0, n) g.add_edge(n + m, i, 1);
    rep(i, 0, m) g.add_edge(n + i, n + m + 1, 1);
    cout << g.flow(n + m, n + m + 1) << '\n';
}
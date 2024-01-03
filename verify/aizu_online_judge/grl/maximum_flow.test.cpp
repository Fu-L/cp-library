#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/max_flow.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    MaxFlow<int> g(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    cout << g.flow(0, n - 1) << '\n';
}
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/max_flow.hpp"
int main(void) {
    int L, R, M;
    cin >> L >> R >> M;
    MaxFlow<int> g(L + R + 2);
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, L + b, 1);
    }
    rep(i, 0, L) {
        g.add_edge(L + R, i, 1);
    }
    rep(i, 0, R) {
        g.add_edge(L + i, L + R + 1, 1);
    }
    cout << g.flow(L + R, L + R + 1) << '\n';
    auto edges = g.edges();
    for(auto e : edges) {
        if(e.from == L + R || e.to == L + R + 1) continue;
        if(e.flow == 1) {
            cout << e.from << ' ' << e.to - L << '\n';
        }
    }
}
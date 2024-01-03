#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/tree_diameter.hpp"
int main(void) {
    int n;
    cin >> n;
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    auto [d, path] = tree_diameter(g);
    cout << d << '\n';
}
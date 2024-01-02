#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/tree_diameter.hpp"
int main(void) {
    int n;
    cin >> n;
    Graph<ll> g(n);
    rep(i, 0, n) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    auto [d, path] = tree_diameter(g);
    cout << d << ' ' << path.size() << '\n';
    for(const auto& p : path) {
        cout << p << '\n';
    }
}
#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
using mint = modint998244353;
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/matrix/matrix.hpp"
#include "../../../src/matrix/gauss_elimination.hpp"
#include "../../../src/matrix/counting_spanning_tree_undirected.hpp"
int main(void) {
    int n, m;
    cin >> n >> m;
    Graph<int> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    cout << counting_spanning_tree_undirected<mint>(g) << '\n';
}
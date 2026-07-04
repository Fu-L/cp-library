#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/modint/static_modint.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/kruskal.hpp"
#include "../../../src/graph/counting_spanning_tree_undirected.hpp"
using mint = modint998244353;
int main() {
    Graph<int> empty(0);
    {
        auto [cost, edges] = kruskal<int>(0, {});
        assert(cost == 0);
        assert(edges.empty());
    }
    assert(counting_spanning_tree_undirected<mint>(empty) == mint(1));
    Graph<int> one(1);
    assert(counting_spanning_tree_undirected<mint>(one) == mint(1));
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
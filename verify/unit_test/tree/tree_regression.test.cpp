#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/centroid.hpp"
#include "../../../src/tree/centroid_decomposition.hpp"
#include "../../../src/tree/rerooting.hpp"
#include "../../../src/tree/tree_diameter.hpp"
int main() {
    Graph<int> empty(0);
    assert(centroid(empty).empty());
    {
        auto [g, root] = centroid_decomposition(empty);
        assert(g.size() == 0);
        assert(root == -1);
    }
    {
        auto [d, path] = tree_diameter(empty);
        assert(d == 0);
        assert(path.empty());
    }
    auto f1 = [](int a, int b) { return a + b; };
    auto f2 = [](int a, int, int) { return a + 1; };
    assert((rerooting<int, int>(empty, f1, f2, 0).empty()));
    Graph<int> one(1);
    assert(centroid(one) == vector<int>{0});
    auto [d, path] = tree_diameter(one);
    assert(d == 0);
    assert(path == vector<int>{0});
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
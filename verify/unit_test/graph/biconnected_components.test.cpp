#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/graph/biconnected_components.hpp"
int main() {
    Graph<int> g(2);
    g.add_edge(0, 1);
    g.add_edge(0, 1);
    BiconnectedComponents<int> bc(g);
    assert(bc.bc.size() == 1);
    assert(bc.bc[0].size() == 2);
    Graph<int> h(3);
    h.add_edge(0, 1);
    h.add_edge(1, 2);
    BiconnectedComponents<int> bc2(h);
    assert(bc2.bc.size() == 2);
    for(const auto& comp : bc2.bc) assert(comp.size() == 1);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/lowest_common_ancestor.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    Graph<int> g(n);
    rep(i, 1, n) {
        int p;
        cin >> p;
        g.add_edge(i, p);
    }
    LowestCommonAncestor<int> tree(g, 0);
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << '\n';
    }
}
#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/lowest_common_ancestor.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    LowestCommonAncestor<int> tree(g);
    while(q--) {
        int s, t, i;
        cin >> s >> t >> i;
        int dist = tree.dist(s, t);
        if(i > dist) {
            cout << -1 << '\n';
            continue;
        }
        int l = tree.lca(s, t);
        int d1 = tree.dist(s, l);
        if(i <= d1) {
            cout << tree.la(s, i) << '\n';
        } else {
            cout << tree.la(t, dist - i) << '\n';
        }
    }
}
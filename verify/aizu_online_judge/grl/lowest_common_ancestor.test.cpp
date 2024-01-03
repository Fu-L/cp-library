#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/lowest_common_ancestor.hpp"
int main(void) {
    int n;
    cin >> n;
    Graph g(n);
    rep(i, 0, n) {
        int k;
        cin >> k;
        rep(j, 0, k) {
            int c;
            cin >> c;
            g.add_edge(i, c);
        }
    }
    LowestCommonAncestor tree(g);
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << '\n';
    }
}
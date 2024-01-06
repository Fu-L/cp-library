#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/heavy_light_decomposition.hpp"
#include "../../../src/data_structure/fenwick_tree.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    HeavyLightDecomposition<int> hld(g);
    while(q--) {
        int s, t, i;
        cin >> s >> t >> i;
        int dist = hld.dist(s, t);
        if(i > dist) {
            cout << -1 << '\n';
            continue;
        }
        int l = hld.lca(s, t);
        int d1 = hld.dist(s, l);
        if(i <= d1) {
            cout << hld.la(s, i) << '\n';
        } else {
            cout << hld.la(t, dist - i) << '\n';
        }
    }
}
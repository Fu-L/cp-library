#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/heavy_light_decomposition.hpp"
#include "../../../src/data_structure/fenwick_tree.hpp"
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    Graph<int> g(n);
    rep(i, 1, n) {
        int p;
        cin >> p;
        g.add_edge(i, p);
    }
    HeavyLightDecomposition<int> hld(g);
    FenwickTree<ll> fw(n);
    rep(i, 0, n) {
        fw.add(hld.idx(i).first, a[i]);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            ll p, x;
            cin >> p >> x;
            fw.add(hld.idx(p).first, x);
        } else {
            int u;
            cin >> u;
            ll ans = 0;
            auto query = [&](int u, int v) -> void {
                ans += fw.sum(u, v);
            };
            hld.subtree_query(u, true, query);
            cout << ans << '\n';
        }
    }
}
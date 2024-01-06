#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/heavy_light_decomposition.hpp"
#include "../../../src/data_structure/fenwick_tree.hpp"
int main(void) {
    int n;
    cin >> n;
    Graph<int> g(n);
    rep(i, 0, n) {
        int k;
        cin >> k;
        rep(j, 0, k) {
            int c;
            cin >> c;
            g.add_edge(i, c);
        }
    }
    HeavyLightDecomposition<int> hld(g);
    FenwickTree<int> fw(n);
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int v, w;
            cin >> v >> w;
            fw.add(hld.idx(v).first, w);
        } else {
            int v;
            cin >> v;
            int ans = 0;
            auto query = [&](int u, int v) -> void {
                ans += fw.sum(u, v);
            };
            hld.path_query(0, v, false, query);
            cout << ans << '\n';
        }
    }
}
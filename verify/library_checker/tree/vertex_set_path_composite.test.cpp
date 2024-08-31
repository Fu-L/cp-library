#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/heavy_light_decomposition.hpp"
#include "../../../src/data_structure/segment_tree.hpp"
using mint = modint998244353;
struct S {
    mint a, b;
};
S op1(S x, S y) {
    return {x.a * y.a, x.b * y.a + y.b};
}
S op2(S x, S y) {
    return {x.a * y.a, y.b * x.a + x.b};
}
S e() {
    return {1, 0};
}
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    Graph<int> g(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    HeavyLightDecomposition<int> hld(g);
    SegmentTree<S, op1, e> seg1(n);
    SegmentTree<S, op2, e> seg2(n);
    rep(i, 0, n) {
        seg1.set(hld.idx(i).first, {a[i], b[i]});
        seg2.set(hld.idx(i).first, {a[i], b[i]});
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int p;
            mint c, d;
            cin >> p >> c >> d;
            seg1.set(hld.idx(p).first, {c, d});
            seg2.set(hld.idx(p).first, {c, d});
        } else {
            int u, v;
            mint x;
            cin >> u >> v >> x;
            mint ans = x;
            auto query = [&](int u, int v) -> void {
                if(u <= v) {
                    S res = seg1.prod(u, v);
                    ans = res.a * ans + res.b;
                } else {
                    S res = seg2.prod(v, u);
                    ans = res.a * ans + res.b;
                }
            };
            hld.path_query(u, v, true, query);
            cout << ans << '\n';
        }
    }
}
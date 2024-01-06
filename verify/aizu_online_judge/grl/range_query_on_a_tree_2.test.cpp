#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E"
#include "../../../src/template/template.hpp"
#include "../../../src/graph/graph_template.hpp"
#include "../../../src/tree/heavy_light_decomposition.hpp"
#include "../../../src/data_structure/lazy_segment_tree.hpp"
struct S {
    long long value;
    long long size;
};
using F = long long;
S op(const S& a, const S& b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(const F& f, const S& x) {
    return {x.value + f * x.size, x.size};
}
F composition(const F& f, const F& g) {
    return f + g;
}
F id() {
    return 0;
}
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
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i, 0, n) seg.set(i, {0, 1});
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            ll v, w;
            cin >> v >> w;
            auto add = [&](int u, int v) -> void {
                seg.apply(u, v, w);
            };
            hld.path_query(0, v, false, add);
        } else {
            int v;
            cin >> v;
            ll ans = 0;
            auto query = [&](int u, int v) -> void {
                ans += seg.prod(u, v).value;
            };
            hld.path_query(0, v, false, query);
            cout << ans << '\n';
        }
    }
}
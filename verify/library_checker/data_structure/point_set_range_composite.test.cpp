#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/data_structure/segment_tree.hpp"
using mint = modint998244353;
struct S {
    mint a, b;
};
S op(S x, S y) {
    return {x.a * y.a, x.b * y.a + y.b};
}
S e() {
    return {1, 0};
}
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<S> v(n);
    rep(i, 0, n) {
        cin >> v[i].a >> v[i].b;
    }
    SegmentTree<S, op, e> seg(v);
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int p;
            mint c, d;
            cin >> p >> c >> d;
            seg.set(p, {c, d});
        } else {
            int l, r;
            mint x;
            cin >> l >> r >> x;
            S res = seg.prod(l, r);
            cout << res.a * x + res.b << '\n';
        }
    }
}
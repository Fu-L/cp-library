#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../../../src/template/template.hpp"
#include "../../../src/template/static_modint.hpp"
#include "../../../src/data_structure/lazy_segment_tree.hpp"
using mint = modint998244353;
struct S {
    mint a;
    ll size;
};
struct F {
    mint a, b;
};
S op(S l, S r) {
    return S{l.a + r.a, l.size + r.size};
}
S e() {
    return S{0, 0};
}
S mapping(F l, S r) {
    return S{r.a * l.a + r.size * l.b, r.size};
}
F composition(F l, F r) {
    return F{r.a * l.a, r.b * l.a + l.b};
}
F id() {
    return F{1, 0};
}
int main(void) {
    int n, q;
    cin >> n >> q;
    vector<S> a(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[i] = S{x, 1};
    }
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(a);
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int l, r, c, d;
            cin >> l >> r >> c >> d;
            seg.apply(l, r, F{c, d});
        } else {
            int i;
            cin >> i;
            cout << seg.get(i).a << '\n';
        }
    }
}
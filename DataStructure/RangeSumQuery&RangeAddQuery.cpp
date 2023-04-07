// vector<S> v(N,{0, 1}); lazy_segtree<S,op,e,F,mapping,composition,id> seg(v); で長さnのセグ木を構築。
// ll ma=seg.prod(l,r).value; でa[l]~a[r-1]のsumを求める。
// seg.apply(l,r,x); でa[l]~a[r-1]にxを加える。
struct S {
    ll value;
    ll size;
};
using F = ll;
S op(S a, S b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(F f, S x) {
    return {x.value + f * x.size, x.size};
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

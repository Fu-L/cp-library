// lazy_segtree<S,op,e,F,mapping,composition,id> seg(n); で長さnのセグ木を構築。
// ll ma=seg.prod(l,r); でa[l]~a[r-1]のminを求める。
// seg.apply(l,r,x); でa[l]~a[r-1]をxに変更。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using S = ll;
using F = ll;
const S INF = 8e18;
const F ID = 8e18;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
S mapping(F f, S x) {
    return (f == ID ? x : f);
}
F composition(F f, F g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}

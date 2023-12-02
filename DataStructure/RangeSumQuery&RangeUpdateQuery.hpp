// vector<S> v(N,{0, 1}); lazy_segtree<S,op,e,F,mapping,composition,id> seg(v); で長さnのセグ木を構築。
// ll ma=seg.prod(l,r).value; でa[l]~a[r-1]のsumを求める。
// seg.apply(l,r,x); でa[l]~a[r-1]をxに変更。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct S {
    ll value;
    ll size;
};
using F = ll;
const F ID = 8e18;
S op(S a, S b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(F f, S x) {
    if(f != ID) x.value = f * x.size;
    return x;
}
F composition(F f, F g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}

// lazy_segtree<S,op,e,F,mapping,composition,id> seg(n); で長さnのセグ木を構築。
// ll mi=seg.prod(l,r); でa[l]~a[r-1]のminを求める。
// seg.apply(l,r,x); でa[l]~a[r-1]にxを加える。
using S=long long;
using F=long long;
const S INF=8e18;
S op(S a,S b){return min(a, b);}
S e(){return INF;}
S mapping(F f,S x){return f+x;}
F composition(F f,F g){return f+g;}
F id(){return 0;}

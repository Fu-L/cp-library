ACLの遅延セグ木
lazy_segtree<S,op,e,F,mapping,composition,id> seg(n); で長さnのセグ木を構築。
ll ma=seg.prod(l,r); でa[l]~a[r-1]のmaxを求める。
seg.apply(l,r,x); でa[l]~a[r-1]にxを加える。
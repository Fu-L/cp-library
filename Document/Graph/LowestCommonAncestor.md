根付き木で最近共通祖先LCAを求める。
LowestCommonAncestor<ll> g(n); でn頂点のグラフを作る。
g.add_edge(a,b,c); でaとbの間にコストcの辺を張る。
g.init() でlcaを求める準備をする。
g.dep[v] で頂点vの深さ、g.par[0][v] で頂点vの親が求まる。
g.lca(a,b) でaとbのLCAを求める。
g.length(a,b) でaとbの最短距離を求める。
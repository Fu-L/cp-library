---
title: LowLink
documentation_of: ../../src/graph/low_link.hpp
---

# LowLink

グラフの橋や関節点を計算します．

橋とはグラフの辺であって，それを取り除くとグラフが非連結になるようなものです．<br>
関節点とはグラフの頂点であって，それを取り除くとグラフが非連結になるようなものです．

## コンストラクタ

```cpp
LowLink<T> lowlink(Graph<T> g)
```

- $n$ 頂点 $m$ 辺のグラフ `g` に対して `lowlink` の初期化を行います．

**計算量**

- $O(n + m)$

## メンバ変数

```cpp
(1) vector<int> lowlink.ord
(2) vector<int> lowlink.low
(3) vector<int> lowlink.articulation
(4) vector<pair<int, int>> lowlink.bridge
```

- (1): 頂点 `i` がDFS木上で何番目に訪れたかを保持しています．
- (2): 頂点 `i` から後退辺を高々 $1$ 回用いて到達できる頂点 $v$ について， `ord[v]` の最小値を保持しています．<br>
後退辺は今回の場合，DFS木に含まれない辺と一致します．
- (3): `g` の関節点の集合を保持しています．
- (4): `g` の橋の集合を保持しています．
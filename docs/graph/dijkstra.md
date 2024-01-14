---
title: dijkstra
documentation_of: ../../src/graph/dijkstra.hpp
---

## dijkstra

```cpp
vector<pair<T, int>> dijkstra(Graph<T> g, int s = 0)
```

$n$ 頂点のグラフ `g` 上で頂点 `s` を始点とした最短経路探索を行います．

返り値は長さ $n$ の `pair` 型の配列です．<br>
`pair` 型の第一要素は頂点 `s` から頂点 `i` までの最短距離を，第二要素は頂点 `i` にたどり着く直前にいた頂点番号を保持しています．

もし頂点 `i` に到達できない場合， `pair` 型の第一要素は `numeric_limits<T>::max()` で，第二要素は $-1$ です．

**制約**

- $0 \leq s < n$

**計算量**

- $O(E \log V)$